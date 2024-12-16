#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int n;

void foo(int sig)
{
    //static int i;
    int x;

    //i = 7;
    if (sig == SIGUSR1)
        x = 1;
    else
        x = 0;
    //i--;
    //if (i == -1)
    //{
        //printf("%d", x);
        //n = 0;
        //i = 7;
    //}
    printf("%d", x);
}

int main()
{
    printf("Receiver PID: %i\n", getpid());
    signal(SIGUSR1, foo);
    signal(SIGUSR2, foo);
    while (1)
    {
        pause();
    }
}
