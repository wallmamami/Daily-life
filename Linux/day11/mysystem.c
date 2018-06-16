#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



int mysystem(char* cmd)
{
    int ret = 0;
    if(NULL == cmd)
        return -1;
    
    //创建子进程
    pid_t id = fork();
    if(id < 0)
        return -1;
    else if(id == 0)//子进程
    {
        char* argv[] = {"sh", "-c", cmd, "NULL"};//查看system文档，文档里面说的
        execvp("/bin/sh", argv);
        exit(127);

    }

    else//父进程
    {
        int s;
        waitpid(id, &s, 0);//不能用wait因为是等指定进程

//        if(WIFEXITED(s))
//          ret = WEXITSTATUS(s);
//        else
//            ret = -1;

    }
    return ret;
}


int main()
{
    mysystem("ls -l");
}
