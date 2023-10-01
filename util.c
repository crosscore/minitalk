/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 05:12:54 by ysakahar          #+#    #+#             */
/*   Updated: 2023/02/09 05:59:47 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		ft_putchar('-');
		num = -n;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

void	ft_error(int flag)
{
	if (flag == -1)
	{
		write(STDERR_FILENO, "Error: Failed to send signal\n", 30);
		exit(1);
	}
}

int	ft_atoi(const char *str)
{
	unsigned int	digit;

	digit = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		digit = digit * 10 + (*str - '0');
		str++;
	}
	return (digit);
}
