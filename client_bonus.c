/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:34:25 by ysakahar          #+#    #+#             */
/*   Updated: 2023/02/09 17:05:53 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_len;

void	client_signal_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "Received ", 10);
		ft_putnbr(g_len);
		write(1, " bytes from server.\n", 21);
	}
	exit (1);
}

void	send_data(char c, int pid)
{
	int	m;
	int	i;

	m = 128;
	i = 0;
	while (m > 0)
	{
		if ((c & m) == m)
			i = kill(pid, SIGUSR1);
		else
			i = kill(pid, SIGUSR2);
		m /= 2;
		usleep(150);
	}
	ft_error(i);
}

int	main(int ac, char **av)
{
	size_t	pid;
	int		i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
			send_data(av[2][i++], pid);
		send_data('\0', pid);
		g_len = i;
		signal(SIGUSR1, client_signal_handler);
		while (42)
			pause();
	}
	else
		write(1, "Error: Invalid format: ./client <server_pid> <message>\n", 63);
	return (0);
}
