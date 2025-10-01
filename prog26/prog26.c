/*
============================================================================
Name : Q26
Author : Kartikey Rana
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 1st Oct, 2025.
============================================================================
*/


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct msg
{
    long mtype;
    char mtext[80];
};

int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
  
    struct msg msg;
    msg.mtype = 10;
    char text[80];
    printf("Enter message:\n");
    scanf("%[^\n]s", text);

    strcpy(msg.mtext, text);
    
    if(msgsnd(msqid, (struct msgbuf *)&msg, 80, 0) == -1){
      printf("Message failed");
    }
    else printf("Message sent successfully");

    return (0);
}

/*
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x613f6a5a 0          root       666        0            0           
0x613f6a5c 1          root       666        0            0           
0x613f6a5e 2          root       666        160          2           

root@ubuntu-dev:~/HandsOnList2/prog26# ./26
Enter message:
hi there
Message sent successfullyroot@ubuntu-dev:~/HandsOnList2/prog26# ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x613f6a5a 0          root       666        0            0           
0x613f6a5c 1          root       666        0            0           
0x613f6a5e 2          root       666        240          3   
*/
