#include <stdio.h>
#include <unistd.h>
#include <signal.h>

char n;
int    ft_power(int nb, int power)
{
    if (power < 0)
        return 0;
    if (power == 0)
        return (1);
    return (nb * ft_power(nb, power - 1));
}
void foo(int sig)
{
    static int i;
    int x;

    if (sig == SIGUSR1)
        x = 1;
    else
        x = 0;
    n = n + ( x * ft_power(2, 7 - i));
    // printf("i = %d | n = %d \n", i, n);
    i++;
    if (i == 8)
    {
        printf("%c", n);
        n = 0;
        i = 0;
    }
    usleep(50);
    fflush(stdout);
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
