#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void foo1(int sig)
{
    kill(466, SIGUSR1);
}
void foo2(int sig)
{
    kill(466, SIGUSR2);
}

int main()
{
    int d;
    int i;
    signal(SIGUSR1, foo1);
    signal(SIGUSR2, foo2);
    i = 7;
    d = 3;
    while (i >= 0)
    {
        int n;

        n = (d >> i) & 1;
        if (n == 1)
            kill(getpid(), SIGUSR1);
        else
            kill(getpid(), SIGUSR2);
        usleep(100);
        i--;
    }
    return 0;
}
