#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>

int CreerSocket()
{	 
	int sock = -1;

	if ((sock=socket(AF_INET, SOCK_DGRAM , 0)) == -1){
		printf("Echec de la creation du socket\n");
		exit(1);
	}
	printf("Succes de la creation du socket\n");
	return sock;
}

void CreerAdresseLocale(struct sockaddr_in*adr_local, int num_port, int sock)
{
	memset((char *)adr_local, 0, sizeof(*adr_local));
	adr_local->sin_family = AF_INET;
	adr_local->sin_port = num_port;
	adr_local->sin_addr.s_addr = INADDR_ANY;
	
	if (bind(sock, (struct sockaddr *)adr_local, sizeof(struct sockaddr_in))) 
		printf("Echec de la creation de l'adresse locale\n");
	else 
		printf("Succes de la creation de l'adresse locale\n");
}


void CreerAdresseDistante(struct sockaddr_in * adr_distant, struct hostent * hp, int num_port, char * nom_machine)
{
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

#define NB_CMD 8

int main (int argc, char **argv)
{
	char machine[] = "localhost";
	int port = 5556;
	extern char *optarg;
	extern int optind;
	int sock_emet;
	int lg_sock_host;
	char *ATCommand[NB_CMD] = {
		"AT*LED=1,0,1073741824,5\r",
		"AT*LED=1,0,1073741824,5\r", //Creating LED Command
		"AT*LED=1,1,1073741824,5\r", // Creating LED Command
		"AT*LED=1,2,1073741824,5\r",
		"AT*LED=1,3,1073741824,5\r",
		"AT*LED=1,4,1073741824,5\r",
		"AT*LED=1,6,1073741824,5\r",
		"AT*LED=1,7,1073741824,5\r"
	};

	struct sockaddr_in adr_local;
	struct sockaddr_in adr_distant;
	struct hostent hp;
	struct sockaddr sock_host;
	
	int i ;

	sock_emet = CreerSocket();
	CreerAdresseDistante(&adr_distant, &hp, port, machine);
	
	/* ENVOI PAR UDP */
	for (i=0; i<NB_CMD; i++) {
		sendto(sock_emet, ATCommand[i], strlen(ATCommand[i]), 0, (struct sockaddr *)&adr_distant, sizeof(adr_distant));
		sleep(1) ;
	}
	
	return 0;
}







