#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PATH_NAME "./tmp"
#define PROJ_ID 0x7777

int main()
{
    key_t k = ftok(PATH_NAME, PROJ_ID);
    if(k < 0)
    {
        perror("ftok");
        return 1;
    }

    int shmid = shmget(k, 4096, IPC_CREAT|IPC_EXCL|0666);
    if(shmid < 0)
    {
        perror("shmget");
        return 2;
    }
    
    char* mem = (char*)shmat(shmid, NULL, 0);

    while(1)
    {
        printf("%s\n", mem);
        sleep(1);
    }

    shmdt(mem);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
