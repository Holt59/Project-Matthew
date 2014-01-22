#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#ifndef MATLAB_MEX_FILE

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>

int 				sock_emet;
int 				sock_recept;
struct sockaddr_in 	adr_local;
struct sockaddr_in 	adr_distant;
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

void _creer_adresse_distante(struct sockaddr_in * adr_distant, int num_port)
{
	memset((char *)adr_distant, 0, sizeof(*adr_distant));
	adr_distant->sin_family = AF_INET;
	adr_distant->sin_port = htons(num_port);
	inet_pton(AF_INET, "192.168.1.255", (void *)&(adr_distant->sin_addr)); // Set the broadcast IP address
}

#endif

void udp_emission_init(int port)
{
#ifndef MATLAB_MEX_FILE
    static int is_initialized = 0;
    
    if(!is_initialized){
        sock_emet = _creer_socket();
        _creer_adresse_distante(&adr_distant, port);
        is_initialized = 1;
    }
#endif
}

void udp_send(char * message, int lg_message)
{
#ifndef MATLAB_MEX_FILE
	sendto(sock_emet, message, lg_message, 0, (struct sockaddr *)&adr_distant, sizeof(adr_distant));
#endif
}

void udp_send_int32(int32_t value, int8_t command)
{
    char buffer[5];
    memcpy((void*)buffer, (const void *)&command, sizeof(int8_t)) ;
    memcpy((void*)(buffer+1), (const void *)&value, sizeof(int32_t)) ;
	udp_send(buffer, sizeof(int8_t)+sizeof(int32_t));
}

void udp_emission_terminate()
{
#ifndef MATLAB_MEX_FILE
    close(sock_emet);
#endif
}

/** RECEPTION **/

#include <map>

std::map <int8_t, int32_t> UDP_RecvValues ;

void udp_reception_init(int port) {
    static int is_initialized = 0;
    
    if(!is_initialized){
#ifndef MATLAB_MEX_FILE
        sock_recept = _creer_socket();
        _creer_adresse_locale(&adr_local, port, sock_recept);
#endif
        is_initialized = 1;
    }
}

int udp_recv(char * message, int lg_message)
{
#ifndef MATLAB_MEX_FILE
	return read(sock_recept, message, lg_message);
#else
    return lg_message ;
#endif
}

int32_t udp_recv_int32 (int8_t command) {
	
	char buffer[sizeof(int8_t) + sizeof(int32_t)];

	while(udp_recv(buffer, sizeof(int8_t) + sizeof(int32_t)) > 0) {
        int8_t cmd = *reinterpret_cast<int8_t*>(buffer) ;
        int32_t value = *reinterpret_cast<int32_t*>(buffer + 1) ;
	}
    
    int32_t value ;
    
    try {
        value = UDP_RecvValues[command] ;
    }
    catch (const std::out_of_range& oor) {
        value = 0 ;
    }
    
	return value ;
}

void udp_reception_terminate()
{
#ifndef MATLAB_MEX_FILE
    close(sock_recept);
#endif
}