#include <stdio.h>
#include <signal.h>


int flag = 0;
void handler(int sig)
{
    flag = 1;
    printf("get a sig: %d\n", sig);
}

int main()
{
    struct sigaction act, oact;
    act.sa_flags = 0;
    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);

    sigaction(2, &act, &oact);

    while(!flag)

    printf("I am quit\n");
    return 0;
}
