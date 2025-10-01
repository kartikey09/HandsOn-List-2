/*
============================================================================
Name : Q32
Author : Kartikey Rana
Description : Write a program to implement semaphore to protect any critical section.
d. remove the created semaphore
Date: 1st Oct, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, 0);
    int a = shmctl(shmid, IPC_RMID, NULL);
    if(a!=-1) printf("Removal Successful");

    return (0);
}

/*Removal Successful*/
