/*
============================================================================
Name : Q10a
Author : Kartikey Rana
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 30th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void segfault_handler(int signum, siginfo_t *info, void *context) {
	printf("\nSegmentation fault\n");
	printf("signal number: %d\n", signum);
	printf("faulty memory address: %p\n", info->si_addr);
	exit(signum);
}
int main (){
	struct sigaction s;
	s.sa_sigaction = segfault_handler;
	s.sa_flags = SA_SIGINFO;

	sigaction(SIGSEGV, &s, NULL);
	
	int *ptr = NULL;
	*ptr = 42;
	return 0;
}

/*
Segmentation fault
signal number: 11
faulty memory address: (nil)
*/
