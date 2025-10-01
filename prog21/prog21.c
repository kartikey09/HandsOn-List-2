/*
============================================================================
Name : Q21
Author : Kartikey Rana
Description :Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 1st Oct, 2025.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

#define FIFO1_PATH "Fifo1"
#define FIFO2_PATH "Fifo2"

int main()
{
    mkfifo(FIFO1_PATH, 0666);
    mkfifo(FIFO2_PATH, 0666);
    
    int a = 0;
    printf("1.\t read/write (program 1)\n2.\t read/write (program 2)\n\t Enter choice: ");
    scanf("%d", &a);
    int fd1 = -1;
    int fd2 = -1;
    char buf[100];

    switch (a)
    {
    case 1:
        fd1 = open("Fifo1", O_WRONLY, 0666);
        write(fd1, "Hello from 1 to 2\n", sizeof("Hello from 1 to 2\n"));
        close(fd1);

        fd2 = open("Fifo2", O_RDONLY, 0666);
        read(fd2, buf, sizeof(buf));
        printf("Message from 2 to 1: %s", buf);

        close(fd2);
        break;
    case 2:
        fd2 = open("Fifo1", O_RDONLY, 0666);
        read(fd2, buf, sizeof(buf));
        printf("Message from writer: %s", buf);
        close(fd2);

        fd1 = open("Fifo2", O_WRONLY, 0666);
        write(fd1, "Hello from 2 to 1\n", sizeof("Hello from 2 to 1\n"));
        close(fd1);

        break;
    default:
        printf("Invalid choice\n");
        break;
    }

    return (0);
}

/*
1.	 read/write (program 1)
2.	 read/write (program 2)
	 Enter choice: 1
Message from 2 to 1: Hello from 2 to 1

1.	 read/write (program 1)
2.	 read/write (program 2)
	 Enter choice: 2
Message from writer: Hello from 1 to 2
*/
