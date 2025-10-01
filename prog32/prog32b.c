/*
============================================================================
Name : Q32
Author : Kartikey Rana
Description : Write a program to implement semaphore to protect any critical section.
b. protect shared memory from concurrent write access
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

    char *data = shmat(shmid, (void *)0, SHM_RDONLY);
    printf("Enter text to put in shared memory: ");
    scanf("%[^\n]s", data);

    printf("Write successful\n");
    shmdt(data);
    return (0);
}

/*
Enter text to put in shared memory: hello world2
Segmentation fault
*/
