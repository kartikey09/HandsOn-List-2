/*
============================================================================
Name : Q9
Author : Kartikey Rana
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 30th Sep, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main (){
	
	printf("\nnow cntrl + c will be ignored for 5 secs\n");
	signal(SIGINT, SIG_IGN);
	sleep(5);

	//resetting SIGINT
	
	signal(SIGINT, SIG_DFL);
	printf("\nSIGINT reset to default, press cntrl + c to end or the program terminates in 5 sec\n");
	sleep(5);
	return 0;
}

/*
now cntrl + c will be ignored for 5 secs
^C^C^C^C^C^C^C
SIGINT reset to default, press cntrl + c to end or the program terminates in 5 sec
^C
root@ubuntu-dev:~/HandsOnList2/prog9#
*/
