/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:34:35 by ysakahar          #+#    #+#             */
/*   Updated: 2023/02/09 17:05:04 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_signal_handler(int sig, siginfo_t *info, void *ptr)
{
	static int	i;
	static char	byte;

	(void)ptr;
	if (sig == SIGUSR1)
		byte = (byte << 1) | 1;
	else if (sig == SIGUSR2)
		byte = (byte << 1) | 0;
	i++;
	if (i == 8)
	{
		ft_putchar(byte);
		if (!byte)
		{
			usleep(500);
			kill(info->si_pid, SIGUSR1);
		}
		i = 0;
		byte = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	write(1, "Server started. PID: ", 22);
	ft_putnbr(pid);
	write(1, "\n", 2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = server_signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
