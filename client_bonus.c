/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:55 by ahakki            #+#    #+#             */
/*   Updated: 2024/12/22 14:32:36 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "utilities.h"

void	f_hundler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("the server receved is : 1\n");
	else
		ft_putstr("the server receved is : 0\n");
}

void	ft_kill(int id, char c)
{
	int	i;
	int	n;

	i = 7;
	while (i >= 0)
	{
		n = (c >> i) & 1;
		if (n == 1)
			kill(id, SIGUSR1);
		else
			kill(id, SIGUSR2);
		usleep(200);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	j;
	int	id;

	signal(SIGUSR1, f_hundler);
	signal(SIGUSR2, f_hundler);
	j = 0;
	if (!av[1] || !av[2] || ac < 3)
		return (0);
	id = ft_atoi(av[1]);
	if (id <= 0)
		return (0);
	while (av[2][j])
	{
		ft_kill(id, av[2][j]);
		j++;
	}
	return (0);
}
