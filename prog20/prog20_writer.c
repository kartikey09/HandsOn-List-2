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

int main (){
	char buffer[] = "hello form writer";
	mkfifo(FIFO_PATH, 0666);
	int fd = open(FIFO_PATH, O_WRONLY);
	printf("\nwriting to FIFO\n");
	write(fd, buffer, strlen(buffer)+1);
	close(fd);
	return 0;
}

/*
writing to FIFO
*/
