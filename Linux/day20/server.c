#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdlib.h>

#define PATH_NAME "./tmp"
#define PROJ_ID 0x7777

union semun{int val;};

int main()
{
    key_t k = ftok(PATH_NAME, PROJ_ID);
    if(k < 0)
    {
        perror("ftok");
        exit(1);
    }

    //创建共享内存
    int shmid = shmget(k, sizeof(int), IPC_CREAT|0644);
    if(shmid < 0)
    {
        perror("shmget");
        exit(1);
    }

    //将共享内存连接到自己的虚拟地址空间
    int *p = (int*)shmat(shmid, NULL, 0);
    if(p == NULL)
    {
        perror("shmat");
        exit(1);
    }

    //创建信号量
    int semid = semget(k, 1, IPC_CREAT|0644);

    //初始化信号量
    union semun s;
    s.val = 0;
    semctl(semid, 0, SETVAL, s);
    int count = 0;
    struct sembuf bs;
    bs.sem_flg = 0;
    bs.sem_num = 0;
    bs.sem_op = 1;

    while(1)
    {
        *p = count++;
        semop(semid, &bs, 1);
    }


}
