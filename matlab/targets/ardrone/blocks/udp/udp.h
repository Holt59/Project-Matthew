#include <stdint.h>

void udp_emission_init(int port);

void udp_send(char * message, int lg_message);

void udp_send_int32(int32_t value);

void udp_emission_terminate();

void udp_reception_init(int port);

int udp_recv(char * message, int lg_message);

int32_t udp_recv_int32();

void udp_reception_terminate();
