#include "comm.h"

void InitSem(int semid, int semnum, int val)
{
    union semun arg;
    arg.val = val;

    semctl(semid, semnum, SETVAL, arg);
}


void PV(int semid, int semnum, int op)
{
    struct sembuf sf;
    sf.sem_flg = 0;
    sf.sem_num = semnum;
    sf.sem_op = op;

    semop(semid, &sf, 1);
}


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
    semctl(semid, num, IPC_RMID);
}
