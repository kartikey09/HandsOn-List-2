/*
============================================================================
Name : Q14
Author : Kartikey Rana
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 30th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main (){
        char write_message[] = "hello world";
        char buffer[100];

	int fd[2];

	pipe(fd);

	write(fd[1], write_message, strlen(write_message)+1);
	printf("wrote message to pipe\n");
	read(fd[0], buffer, sizeof(buffer));
	printf("read message from pipe: \n%s", buffer);
	return 0;
}
/*
wrote message to pipe
read message from pipe: 
hello world
*/
