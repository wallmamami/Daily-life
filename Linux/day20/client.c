#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define PATH_NAME "./tmp"
#define PROJ_ID 0x7777

int main()
{
    key_t k = ftok(PATH_NAME, PROJ_ID);
    int shmid = shmget(k, sizeof(int), 0);

    int semid = semget(k, 0, 0);
    if(semid < 0)
    {
        printf("semget error!\n");
        return -1;
    }

    int *p = (int *)shmat(shmid, NULL, 0);
    if(p == NULL)
    {
        printf("shmat error\n");
        return -2;
    }
    struct sembuf s;
    s.sem_flg = 0;
    s.sem_num = 0;
    s.sem_op = -1;

    while(1)
    {
        semop(semid, &s, 1);
        printf("%d\n", *p);
        sleep(1);
    }
}
