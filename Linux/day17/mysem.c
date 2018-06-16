#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include "comm.h"



#define PATH_NAME "./tmp"
#define PROJ_ID 0x7777


int main()
{
    key_t k = ftok(PATH_NAME, PROJ_ID);
    if(k < 0)
    {
        printf("ftok error!\n");
        return -1;
    }

    int semid = semget(k, 1, IPC_CREAT|IPC_EXCL|0666);
    if(semid < 0)
    {
        printf("semget error!\n");
        return -1;
    }
   
    InitSem(semid, 0, 1);
    
    pid_t id = fork();
    if(id < 0)
    {
        printf("fork error!\n");
        return 1;
    }

    else if (id ==0)
    {
        while(1)
        {
            P(semid, 0);
            printf("A");
            sleep(1);
            fflush(stdout);
            printf("A");
            sleep(1);
            fflush(stdout);
            V(semid, 0);
        }

    }

    else
    {
        while(1)
        {
            P(semid, 0);
            printf("B");
            sleep(1);
            fflush(stdout);
            printf("B");
            sleep(1);
            fflush(stdout);
            V(semid, 0);
        }
    }
}
