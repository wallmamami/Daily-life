#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>


void do_exec(int argc, char* argv[])
{
    pid_t id = fork();

    if(id == 0)
    {
        execvp(argv[0], argv);
        printf("command %s not fount\n", argv[0]);
        exit(1);
    }

    else
    {
        waitpid(id, NULL, 0);
    }
}

void do_parse(char* buf)
{
    char* argv[8];
    int argc = 0;
    int flag = 0;
    int i = 0;

    for(i=0; buf[i]!='\0'; i++)
    {
        if(buf[i]==' ')//说明在单词外面
        {
            buf[i] = '\0';
            flag = 0;
        }
        else if(buf[i] != ' ' && flag == 0)//说明刚进入单词
        {
            argv[argc++] = buf+i;//将单词首地址放入argv，
            flag = 1;
        }
    }
    argv[argc] = NULL;

    do_exec(argc, argv);//进程替换·
}

int main()
{
    char buf[100];
    while(1)
    {
        printf("wj@local>");
        memset(buf, 0x00, sizeof(buf));
        scanf("%[^\n]%*c", buf);//读入一行字符串，而这串字符里面可能有空格、制表符等空白字符
        do_parse(buf);//将这行字符串分割成一个一个命令，即一个一个单词

    }
}
