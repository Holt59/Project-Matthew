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

#endif

void udp_emission_init(int port);

void udp_send(char * message, int lg_message);

void udp_send_int32(int32_t value, int8_t command);

void udp_emission_terminate();

void udp_reception_init(int port);

int udp_recv(char * message, int lg_message);

int32_t udp_recv_int32(int8_t command);

void udp_reception_terminate();
