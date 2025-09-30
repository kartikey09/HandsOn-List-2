/*
============================================================================
Name : Q16
Author : Kartikey Rana
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 30th Sep, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
	int p2c[2];
	int c2p[2];
	char pbuffer[100];
	char cbuffer[100];
	char pmessage[] = "message from parent";
	char cmessage[] = "message from child";
	pipe(p2c);
	pipe(c2p);

	int pid = fork();

	if(pid > 0){
		//parent
		printf("\nparent writing to child\n");
		write(p2c[1], pmessage, strlen(pmessage)+1);
		printf("\n=== message written to child, parent sleeps now ===\n");
		sleep(2);
		printf("\n=== parent up now ===\n");
		read(c2p[0], pbuffer, sizeof(pbuffer));
		printf("\nparent reading from child : %s\n", pbuffer);
		wait(NULL);
		printf("\nparent exits\n");
		exit(0);
	} else {
		//child
		sleep(1);
		read(p2c[0], cbuffer, sizeof(cbuffer));
		printf("\nchild reading from parent : %s\n", cbuffer);
                write(c2p[1], cmessage, strlen(cmessage)+1);
                printf("\n=== message written to parent, child sleeps now ===\n");
                sleep(1);
                printf("\n=== child up now ===\n");
                printf("\nchild exits\n");
		exit(0);
	}
	return 0;
}

/*
 parent writing to child

=== message written to child, parent sleeps now ===

child reading from parent : message from parent

=== message written to parent, child sleeps now ===

=== parent up now ===

parent reading from child : message from child

=== child up now ===

child exits

parent exits
*/
