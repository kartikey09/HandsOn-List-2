/*
============================================================================
Name : Q1c
Author : Kartikey Rana
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
Date: 7th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>


void alert(int signum){
	printf("---timer expired---\n");
}

int main(){
	struct itimerval timer;
	signal(SIGPROF, alert);

	timer.it_value.tv_sec = 3;
	timer.it_value.tv_usec = 0;

	timer.it_interval.tv_sec = 3;
	timer.it_interval.tv_usec = 0;

	setitimer(ITIMER_PROF, &timer, NULL);

	printf("timer set for 3 sec \n");
	while(1){
		getpid();
	}

	return 0;
}
