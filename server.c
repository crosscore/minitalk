/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:34:38 by ysakahar          #+#    #+#             */
/*   Updated: 2023/02/09 16:20:54 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_signal_handler(int sig)
{
	static int	i;
	static char	byte;

	if (sig == SIGUSR1)
		byte = (byte << 1) | 1;
	else if (sig == SIGUSR2)
		byte = (byte << 1) | 0;
	i++;
	if (i == 8)
	{
		ft_putchar(byte);
		i = 0;
		byte = 0;
	}
}

int	main(void)
{
	size_t	pid;

	pid = getpid();
	write(1, "Server started. PID: ", 22);
	ft_putnbr(pid);
	write(1, "\n", 2);
	signal(SIGUSR1, server_signal_handler);
	signal(SIGUSR2, server_signal_handler);
	while (1)
		pause();
	return (0);
}
