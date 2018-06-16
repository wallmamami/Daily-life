#include "comm.h"

//信号量集初始化
void InitSem(int semid, int num, int val)//num为信号量集的第num个元素
{
    union semun arg;
    arg.val = val;
    semctl(semid, num, SETVAL, arg);
}


//PV
static void PV(int semid, int num, int op)
{
    struct sembuf sf;
    sf.sem_num = num;
    sf.sem_op = op;
    sf.sem_flg = 0;

    semop(semid, &sf, 1);
}

//P操作(-1)
void P(int semid, int num)
{
    PV(semid, num, -1);
}

void V(int semid, int num)
{
    PV(semid, num, 1);
}

void DestroySem(int semid, int num)
{
    semctl(semid, 0, IPC_RMID);
}
