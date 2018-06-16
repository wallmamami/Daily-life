#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{
    pid_t id = fork();

    if(id > 0)//爷爷
    {
        wait(NULL);
             while(1)
            {
                printf("X");
                fflush(stdout);
                sleep(1);
            
            } 
    }

    if(id == 0)//子进程
    {
        pid_t ID = fork();//子进程创建孙子进程
        if(ID == 0)
        {
            while(1)
            {
                printf("O");
                fflush(stdout);
                sleep(1);
            }
            
        }

        if(ID > 0)
        {
            printf("我是爸爸!\n");
            exit(0);
        }
    }
}

