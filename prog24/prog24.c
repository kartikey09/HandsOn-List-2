/*
============================================================================
Name : Q24
Author : Kartikey Rana
Description : Write a program to create a message queue and print the key and message queue id.
Date: 1st Oct, 2025.
============================================================================
*/


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    printf("Key: %d, ID: %d\n", key, msqid);
    return(0);
}

/*
Key: 1631545946, ID: 0
*/
