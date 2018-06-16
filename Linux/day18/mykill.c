#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

//mykill -9 3333
int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("shabi!\n");
        return 1;
    }

    kill(atoi(argv[2]), atoi(argv[1]));
}
