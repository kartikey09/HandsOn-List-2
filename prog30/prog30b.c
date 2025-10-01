/*
============================================================================
Name : Q30b
Author : Kartikey Rana
Description : Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite.
Date: 1st Oct, 2025.
============================================================================
*/


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    key_t key = ftok(".", 'a');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    int shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    char *data = shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        return 1;
    }

    printf("Enter text to put in shared memory: ");
    scanf("%[^\n]s", data);

    printf("Write successful: %s\n", data);
    shmdt(data);

    return 0;
}
/*
Enter text to put in shared memory: hello world
Write successful: hello world
*/
