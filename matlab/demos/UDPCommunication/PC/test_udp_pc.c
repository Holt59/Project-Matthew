#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>

int 				sock_emet;
int 				sock_recept;
struct sockaddr_in 	adr_local;
struct sockaddr_in 	adr_distant;
struct hostent 		hp;
struct sockaddr 	sock_host;
socklen_t 			lg_sock_host;


int _creer_socket()
{
	int sock = -1;
	int broadcast = 1;
	 
	if ((sock=socket(AF_INET, SOCK_DGRAM , 0)) == -1)
	{
		printf("Echec de la creation du socket : %s\n", strerror(errno));
		exit(1);
	}
	int flags = fcntl(sock, F_GETFL, 0) ;
	fcntl(sock, F_SETFL, flags | O_NONBLOCK) ;

	if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcast,
        sizeof broadcast) == -1) {
        perror("setsockopt (SO_BROADCAST)");
        exit(1);
    }

	printf("Succes de la creation du socket\n");

	return sock;
}

void _creer_adresse_locale(struct sockaddr_in *adr_local, int num_port, int sock)
{
	memset((char *)adr_local, 0, sizeof(*adr_local));
	adr_local->sin_family = AF_INET;
	adr_local->sin_port = htons(num_port);
	adr_local->sin_addr.s_addr = INADDR_ANY;
	
	if (bind(sock, (struct sockaddr *)adr_local, sizeof(struct sockaddr_in))) 
		printf("Echec de la creation de l'adresse locale : %s\n", strerror(errno));
	else 
		printf("Succes de la creation de l'adresse locale\n");
}

void _creer_adresse_distante(struct sockaddr_in * adr_distant, int num_port, struct hostent * hp)
{
	char nom_machine[] = "192.168.1.1";

	//memset((char*)&adr_distant, 0, sizeof(*adr_distant));
	adr_distant->sin_family = AF_INET;
	adr_distant->sin_port = htons(num_port);
	
	if((hp = gethostbyname(nom_machine)) == NULL){
		printf("Erreur GetHostByName \n");
		exit(1);
	}
	else printf("Succes de la creation de l'adresse distante\n");

	memcpy((char*)&(adr_distant->sin_addr.s_addr), hp->h_addr, hp->h_length);
}

void udp_emission_init(int port)
{
    static int is_initialized = 0;
    
    if(!is_initialized){
        sock_emet = _creer_socket();
        _creer_adresse_distante(&adr_distant, port, &hp);
        is_initialized = 1;
    }
}

void udp_send(char * message, int lg_message)
{
	sendto(sock_emet, message, lg_message, 0, (struct sockaddr *)&adr_distant, sizeof(adr_distant));
}

void udp_send_int32(int32_t value)
{
	printf("send value %d\n", value);
	udp_send((char*)&value, sizeof(int32_t));
}

void udp_emission_terminate()
{
    close(sock_emet);
}

void udp_reception_init(int port)
{
    static int is_initialized = 0;
    
    if(!is_initialized){
        sock_recept = _creer_socket();
        _creer_adresse_locale(&adr_local, port, sock_recept);
        is_initialized = 1;
    }
}

int udp_recv(char * message, int lg_message)
{
	return read(sock_recept, message, lg_message);
}

int32_t udp_recv_int32()
{
	static int32_t value = 0;
	char buffer[sizeof(int32_t)];

	while(udp_recv(buffer, sizeof(int32_t)) > 0)
	{
		memcpy(&value, buffer, sizeof(int32_t));
	}

	return value;
}

void udp_reception_terminate()
{
    close(sock_recept);
}

int main()
{
	int envoi;

	udp_reception_init(9000);
	udp_emission_init(9000);

	while(1)
	{
		scanf("%d", &envoi);
		udp_send_int32(envoi);
		usleep(5000);
		//printf("\r%4d", udp_recv_int32());
		//fflush(stdout);
	}

	return 0;
}