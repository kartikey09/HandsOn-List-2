/*
============================================================================
Name : Q1
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


void alert(){
	printf("---timer expired---\n");
}

int main(){
	struct itimerval timer;
	signal(SIGALRM, alert);

	timer.it_value.tv_sec = 10;
	timer.it_value.tv_usec = 0;

	timer.it_interval.tv_sec = 10;
	timer.it_interval.tv_usec = 0;

	setitimer(ITIMER_REAL, &timer, NULL);

	printf("timer set for 10 sec \n");
	while(1)
		pause();

	return 0;
}
