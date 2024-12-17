#include <stdio.h>
#include <unistd.h>
#include <signal.h>

unsigned char n = 0;
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
    int x = 0;

    if (sig == SIGUSR1)
        x = 1;
    else if (sig == SIGUSR2)
        x = 0;
    // printf("++++++++{before n : %d | x : %d | power : %d}+++++++++\n",n,x,ft_power(2, 7 - i));
    n = n + ( x * ft_power(2, 7 - i));
    // printf("i = %d | n = %d \n", i, n);
    // printf("++++++++{after n : %d }+++++++++\n",n);

    i++;
    if (i == 8)
    {
        // printf("%c\n", n);
        write(1, &n, 1);
        n = 0;
        i = 0;
    }
    fflush(stdout);
}

int main()
{
    printf("Receiver PID: %i\n", getpid());
    signal(SIGUSR1, foo);
    signal(SIGUSR2, foo);
    while (1)
    {

    }
    
}
