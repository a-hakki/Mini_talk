#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void foo1(int sig)
{
    return;
}
void foo2(int sig)
{
    return;
}

int main(int ac, char **av)
{
    int i;
    int j;
    int id;

    j = 0;
    if (!av[1] || !av[2])
    {
        return (0);
    }
    id = atoi(av[1]);
    signal(SIGUSR1, foo1);
    signal(SIGUSR2, foo2);
    while (av[2][j])
    {
        i = 7;
        while (i >= 0)
        {
            int n;

            n = ((av[2][j]) >> i) & 1;
            if (n == 1)
            {
                printf("1\n");
                kill(id, SIGUSR1);
            }
            else
            {
                printf("0\n");
                kill(id, SIGUSR2);
            }
            usleep(10000);
            i--;
        }
        //printf("%c\n", av[2][j]);
        j++;
    }
    
    
    return 0;
}
