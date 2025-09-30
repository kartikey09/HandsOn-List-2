/*
============================================================================
Name : Q20
Author : Kartikey Rana
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 30th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define FIFO_PATH "/tmp/myfifo"

int main(){
	char buffer[100];
	
	printf("reader waiting for writer to write\n");
	int fd = open(FIFO_PATH, O_RDONLY);
	printf("Reading from FIFO\n");

	read(fd, buffer, sizeof(buffer));

	printf("the read message is: %s\n",buffer);
       	close(fd);
	return 0;      
}

/*
reader waiting for writer to write
Reading from FIFO
the read message is: hello form writer
*/
