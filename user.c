#include <stdio.h>
// #include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void foo(int sig)
{
    printf("1 ");    
}
void foo2(int sig)
{
    printf("0 ");    
}
int main()
{
    int n;
    signal(SIGUSR1, foo);
    signal(SIGUSR2, foo2);

    int d = 3;
    for (int i = 7; i >= 0; i--)
    {
        n = (d >> i) & 1;
        n == 0 ? kill(getpid(), SIGUSR2) : kill(getpid(), SIGUSR1);
    }
}