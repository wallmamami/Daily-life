#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include "add.h"

union semun{int val;};

int main()
{
    //打开文件，从文件中读取内容用加法方法进行计算
    int fd = open("tmp", O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    char buf[1024] = {};
    int a, b;
    read(fd, buf, 1024);
    close(fd);    
    sscanf(buf, "%d+%d", &a, &b);

    //调用动态库执行加法
    int r = add(a, b);

    //将结果放到共享内存
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "%d+%d=%d", a, b, r);//将执行结果格式化到buf
    int shmid = shmget(1234, strlen(buf), IPC_CREAT|0644);
    if(shmid < 0)
    {
        perror("shmget");
        exit(1);
    }

    char *p = (char*)shmat(shmid, NULL, 0);
    strcpy(p, buf);

    //创建信号量，执行v操作
    int semid = semget(1234, 1, IPC_CREAT|0644);
    if(semid < 0)
    {
        perror("semget");
        exit(1);
    }
    
    union semun arg;
    arg.val = 0;
    semctl(semid, 0, SETVAL, arg);
    
    struct sembuf s;
    s.sem_flg = 0;
    s.sem_num = 0;
    s.sem_op = 1;
    semop(semid, &s, 1);

    //创建子进程，子进程进程替换
    pid_t id = fork();
    if(id == 0)
    {
        execlp("./rd", "rd", NULL);
        perror("execlp");
        exit(1);
    }

    wait(NULL);
}
