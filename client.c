/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:34:29 by ysakahar          #+#    #+#             */
/*   Updated: 2023/02/09 17:06:01 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_data(char c, int pid)
{
	int	m;
	int	i;

	m = 128;
	i = 0;
	while (m > 0)
	{
		if ((m & c) == m)
			i = kill(pid, SIGUSR1);
		else
			i = kill(pid, SIGUSR2);
		m >>= 1;
		usleep(150);
	}
	ft_error(i);
}

int	main(int argc, char **argv)
{
	size_t	pid;
	size_t	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_data(argv[2][i], pid);
			i++;
		}
		send_data('\0', pid);
	}
	else
		write(1, "Error: Invalid format: ./client <server_pid> <message>\n", 63);
	return (0);
}
