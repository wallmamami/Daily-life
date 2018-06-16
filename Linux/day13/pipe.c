#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int fd[2];
    int ret = pipe(fd);

    if(ret < 0)
    {
        perror("pipe");
        return 1;
    }

    pid_t id = fork();
    if(id < 0)
    {
        perror("fork");
        return 1;
    }

    else if(id == 0)//子进程，写端
    {
        close(fd[0]);//关闭读端

        char* msg = "hello f, i m c!\n";
        while(1)
        {
            sleep(1);
            write(fd[1], msg, strlen(msg));
        }
    }
    else//父进程， 读端
    {
        char buf[64];
        close(fd[1]);//关闭写端
        while(1)
        {

            size_t s =  read(fd[0], buf, sizeof(buf)-1);
            if(s > 0)
            {
                buf[s] = '\0';
                printf("f say: %s\n", buf);
            }
        }
    }
}
