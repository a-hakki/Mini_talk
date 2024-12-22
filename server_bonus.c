/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:36:26 by ahakki            #+#    #+#             */
/*   Updated: 2024/12/22 14:31:33 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "utilities.h"

int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}

void	f_hundler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static int	g_n;
	int			x;

	(void)context;
	if (sig == SIGUSR1)
	{
		x = 1;
		kill(info->si_pid, SIGUSR1);
	}
	else
	{
		x = 0;
		kill(info->si_pid, SIGUSR2);
	}
	g_n = g_n + (x * ft_power(2, 7 - i));
	i++;
	if (i == 8)
	{
		write(1, &g_n, 1);
		g_n = 0;
		i = 0;
	}
	return ;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = f_hundler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("Receiver PID");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (1)
	{
	}
}
