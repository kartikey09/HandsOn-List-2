/*
============================================================================
Name : Q13a
Author : Kartikey Rana
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 30th Sep, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

void interruptHandler(int signum){
	printf("\nSIGSTOP caught");
}

int main (){
	printf("process started with pid: %d\n", getpid());
	struct sigaction s;
	s.sa_handler = interruptHandler;
	sigaction(SIGSTOP, &s, NULL);
	while(1)pause();
	return 0;
}
/*
process started with pid: 1562

[1]+  Stopped
*/	
