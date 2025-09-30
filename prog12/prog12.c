/*
============================================================================
Name : Q12
Author : Kartikey Rana
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 30th Sep, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(){
	int child = fork();
	if(child > 0){
		printf("\nparent going to sleep so child can kill\n");
		sleep(1);
	} else {
		printf("\nchild will kill parent now \n");
		kill(getppid(),SIGKILL);
	}
	return 0;
}

/*
parent going to sleep so child can kill

child will kill parent now
Killed
*/
