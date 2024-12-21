/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:36:26 by ahakki            #+#    #+#             */
/*   Updated: 2024/12/21 19:21:42 by ahakki           ###   ########.fr       */
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

void	foo(int sig)
{
	static int	i;
	static int	g_n;
	int			x;

	if (sig == SIGUSR1)
		x = 1;
	else
		x = 0;
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
	ft_putstr("Receiver PID ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	signal(SIGUSR1, foo);
	signal(SIGUSR2, foo);
	while (1)
	{
	}
}
