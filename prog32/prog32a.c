/*
============================================================================
Name : Q32
Author : Kartikey Rana
Description : Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
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
    printf("Enter text to put in shared memory: ");
    scanf("%[^\n]s", data);
    
    printf("Write successful\n");
    
    return(0);
}
/*
Enter text to put in shared memory: hello world 
Write successful
*/
