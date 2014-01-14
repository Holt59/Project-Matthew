#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int sock_emet;
int sock_recept;
struct sockaddr_in adr_local;
struct sockaddr_in adr_distant;
struct hostent hp;
struct sockaddr sock_host;
socklen_t lg_sock_host;

int CreerSocket()
{
	int sock = -1;
	 
	if ((sock=socket(AF_INET, SOCK_DGRAM , 0)) == -1)
	{
		printf("Echec de la creation du socket : %s\n", strerror(errno));
		exit(1);
	}
	int flags = fcntl(sock, F_GETFL, 0) ;
	fcntl(sock, F_SETFL, flags | O_NONBLOCK) ;
	printf("Succes de la creation du socket\n");

	return sock;
}

void CreerAdresseLocale(struct sockaddr_in *adr_local, int num_port, int sock)
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

void CreerAdresseDistante(struct sockaddr_in * adr_distant, struct hostent * hp, int num_port, char * nom_machine)
{
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
	char machine[] = "localhost";

	sock_emet = CreerSocket();
	CreerAdresseDistante(&adr_distant, &hp, port, machine);
}

void udp_send(char * message, int lg_message)
{
	sendto(sock_emet, message, lg_message, 0, (struct sockaddr *)&adr_distant, sizeof(adr_distant));
}

void udp_send_int32(int32_t value)
{
	udp_send(&value, sizeof(int32_t));
}

void udp_reception_init(int port)
{
	sock_recept = CreerSocket();
	CreerAdresseLocale(&adr_local, port, sock_recept);
}

int udp_recv(char * message, int lg_message)
{
	return read(sock_recept, message, lg_message);
}

int32_t udp_recv_int32()
{
	static int32_t value = 0;
	char buffer[sizeof(int32_t)];

	while(udp_recv(buffer, sizeof(int32_t)) != -1)
	{
		memcpy(value, buffer, sizeof(int32_t));
	}

	return value;
}

int main (int argc, char **argv)
{
	char message_reception[10];
	char message_emission[10] = "abcdefghij";
	
	udp_reception_init(8000);
	udp_emission_init(8001);

	while(1)
	{
		sleep(1);
		udp_send(message_emission, 10);
		if (udp_recv(message_reception, 10) > 0) {
			printf("%s\n", message_reception);
		}
	}
}
