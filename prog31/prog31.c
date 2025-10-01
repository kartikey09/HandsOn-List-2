/*
============================================================================
Name : Q31
Author : Kartikey Rana
Description : Write a program to create a semaphore and initialize value to the semaphore.
		a. Create a binary semaphore.
		b. Create a counting semaphore.
Date: 1st Oct, 2025.
============================================================================
*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

struct semun
{
    int val;                   
    struct semid_ds *buf;      
    unsigned short int *array; 
};

int main()
{
    struct semun arg;
    key_t k = ftok(".", 'a');
    int semid = semget(k, 1, IPC_CREAT | 0666);

    int choice;
    printf("Choose an option:\n1.) Binary Semaphore\n2.) Counting Semaphore\n=> ");
    scanf("%d", &choice);

    if(choice == 1){
        printf("Creating binary semaphore\n");
        arg.val = 1;       
    }
    else if(choice == 2){
        printf("Creating Counting Semaphore");
        arg.val = 5;
    }
    else printf("Can't create semaphore");
    
    semctl(semid, 0, SETVAL, arg);
    
    return (0);
}

/*Choose an option:
1.) Binary Semaphore
2.) Counting Semaphore
=> 2
Creating Counting Semaphore*/
