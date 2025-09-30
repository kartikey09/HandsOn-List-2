/*
============================================================================
Name : Q11
Author : Kartikey Rana
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 30th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <bits/sigaction.h>

int main(){
    struct sigaction sa;

    sa.sa_handler = SIG_IGN;
    printf("Ignoring SIGINT for 10 seconds\n");
    sigaction(SIGINT,&sa,NULL);
    sleep(10);
    
    sa.sa_handler = SIG_DFL;
    printf("\nDefault of SIGINT\n");
    sigaction(SIGINT,&sa,NULL);
    
    for(;;){};
    
    return(0);
}



/*
Ignoring SIGINT for 10 seconds
^C^C^C^C^C^C
Default of SIGINT
^C
root@ubuntu-dev:~/HandsOnList2/prog11# 
*/
