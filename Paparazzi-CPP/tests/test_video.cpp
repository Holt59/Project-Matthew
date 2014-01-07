#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>
#include <errno.h>

int main (int argc, char *argv[]) {
   
    int fd ;
    char buff[256] ;
    int count  ;

    if (argc != 2) {
	fprintf(stderr, "Missing parameter.\n") ;
	return 1 ;
    }

    if ((fd = open(argv[1], O_RDONLY)) == -1) {
	fprintf (stderr, "Error opening file: %s\n", strerror(errno)) ;
	return 1 ;
    }
/*
    if (-1 == ioctl (fd, VIDIOC_S_FMT)) {
	fprintf (stderr, "Error: VIDIOC_F_FMT");
	return 1 ;
    }
*/
    while ((count = read(fd, buff, 256))) {
	buff[count-1] = '\0' ;
	printf("%s", buff) ;
	fflush(stdout) ;
    }

    return 0 ;

}
