/*
============================================================================
Name : Q13b
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
#include <sys/types.h>

int main(int argc, char *argv[]) {
    pid_t target;
    target = atoi(argv[1]);

    printf("\n Sending SIGSTOP to the process %d", target);

    if(kill(target, SIGSTOP)){
	    printf("\nsuccessfully stopped the process ");
    }
    return 0;
}
/*
 1562
 Sending SIGSTOP to the process 1562
 */
