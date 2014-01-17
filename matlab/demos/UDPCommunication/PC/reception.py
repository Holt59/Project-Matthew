from socket import *

s = socket(AF_INET, SOCK_DGRAM)
s.bind(('', 9000))
while True:
	s.recv(4)