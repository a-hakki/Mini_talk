/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:47:57 by ahakki            #+#    #+#             */
/*   Updated: 2024/12/21 19:07:10 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

int     ft_atoi(char const *str);
void	ft_putstr(char *s);
void     ft_putchar(char c);
void	ft_putnbr(int n);

#endif
