#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>




union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                (Linux-specific) */

};

void InitSem(int semid, int semnum, int val);
void PV(int semid, int semnum, int op);
void P(int semid, int num);
void V(int semid, int num);
void DestroySem(int semid, int num);
