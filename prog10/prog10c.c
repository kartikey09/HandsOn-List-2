/*
============================================================================
Name : Q10c
Author : Kartikey Rana
Description : Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE
Date: 30th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void Interrupt_handler(int signum, siginfo_t *info, void *context) {
	printf("\nFloating point exception caught\n");
	printf("signal number: %d\n", signum);
	exit(signum);
}


int main (){
	struct sigaction s;
	s.sa_sigaction = Interrupt_handler;
	s.sa_flags = SA_SIGINFO;
	sigemptyset(&s.sa_mask);
	sigaction(SIGFPE, &s, NULL);
	int x = 10;
    	int y;
	printf("enter 0 \n");
	scanf("%d",&y);
    	int z = x / y;
	
}
/*
enter 0 
Floating point exception caught
signal number: 8
*/
