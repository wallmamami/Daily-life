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

int main()
{
    //打开共享内存和信号量
    int shmid = shmget(1234, 0, 0);
    int semid = semget(1234, 0, 0);

    //将共享内存挂载到自己的虚拟地址
    char *p = (char*) shmat(shmid, NULL, 0);

    //执行P操作
    struct sembuf s;
    s.sem_flg = 0;
    s.sem_num = 0;
    s.sem_op = -1;

    semop(semid, &s, 1);

    //将内容写入文件
    int fd = open("tmp", O_WRONLY);
    write(fd, p, strlen(p));  
    close(fd);
}
