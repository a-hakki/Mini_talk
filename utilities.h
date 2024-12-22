/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:47:57 by ahakki            #+#    #+#             */
/*   Updated: 2024/12/22 14:29:24 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

int		ft_atoi(char const *str);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);

#endif
