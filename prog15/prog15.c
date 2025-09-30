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
	pid_t pid;
	int fd[2];
	pipe(fd);

	pid = fork();

	if(pid>0){
		//parent
		close(fd[0]);
		write(fd[1], write_message, strlen(write_message)+1);
		close(fd[1]);
		wait(NULL);
		printf("\n Parent exiting\n");
	} else {
		//child
		close(fd[1]);
		read(fd[0], buffer, strlen(write_message));
		close(fd[0]);
		printf("\n child read the message: %s\n", buffer);
	}

	return 0;
}

/*
child read the message: hello world

 Parent exiting
*/
