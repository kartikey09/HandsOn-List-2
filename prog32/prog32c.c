/*
============================================================================
Name : Q32
Author : Kartikey Rana
Description : Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore
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
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    char *data = shmat(shmid, (void *)0, 0);
    printf("Detachment Successful\n");
    shmdt(data);

    return (0);
}

/*
Detachment Successful
*/
