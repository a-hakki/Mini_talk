/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:55 by ahakki            #+#    #+#             */
/*   Updated: 2024/12/21 15:17:22 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	foo(int sig)
{
	if (sig == SIGUSR1)
		printf("the server receved is : 1\n");
	else
		printf("the server receved is : 0\n");
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
	int	i;
	int	j;
	int	id;
	int	n;

	signal(SIGUSR1, foo);
	signal(SIGUSR2, foo);
	j = 0;
	if (!av[1] || !av[2])
		return (0);
	id = atoi(av[1]);
	while (av[2][j])
	{
		ft_kill(id, av[2][j]);
		j++;
	}
	return (0);
}
