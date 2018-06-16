#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int main()
{
    pid_t id = fork();
    
    if(id > 0)//father
    {
       int  status = 0;
       pid_t id =  waitpid(-1, &status, WNOHANG);

       if(WIFEXITED(status))
       {
           printf("exit: %d", WEXITSTATUS(status));
       }

       if(WIDSIGNALED(status))
       {
           printf("signal:%d", WIERMSIG(status));
       }

       printf("child:%d\n", id);
    }

    if(id == 0)//child
    {
        while(1)
            ;
    }
        
}
