/*
============================================================================
Name : Q3
Author : Kartikey Rana
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 29th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

int main(){
	struct rlimit rlim;
	
	getrlimit(RLIMIT_NOFILE, &rlim);
	printf("soft limit is: %lu\n", rlim.rlim_cur);
	printf("hard limit is: %lu\n", rlim.rlim_max);

	printf("\nsetting new limits now\n");
	
	rlim.rlim_cur = 50;
	rlim.rlim_max = 100;

	setrlimit(RLIMIT_NOFILE, &rlim);
	getrlimit(RLIMIT_NOFILE, &rlim);

	printf("new soft limit is: %lu\n", rlim.rlim_cur);
	printf("new hard limit is: %lu\n", rlim.rlim_max);
	
	return 0;
}

/*
soft limit is: 1048576
hard limit is: 1048576

setting new limits now
new soft limit is: 50
new hard limit is: 100
*/
