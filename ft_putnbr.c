/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:45:30 by ahakki            #+#    #+#             */
/*   Updated: 2024/12/21 19:10:38 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

static void	ftb_putchar(int c)
{
	c = c + 48;
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == 0)
		ftb_putchar(n);
	if (n == -2147483648)
	{
		ft_putnbr((n / 10));
		ftb_putchar(8);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else if (n > 0)
	{
		if (n <= 9)
			ftb_putchar(n);
		else
		{
			ft_putnbr((n / 10));
			ftb_putchar(n % 10);
		}
	}
}