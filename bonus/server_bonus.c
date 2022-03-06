/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:16:47 by ilahyani          #+#    #+#             */
/*   Updated: 2022/03/06 15:47:45 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_power = 7;

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	byte = 0;
	static int	og_pid;

	(void) context;
	if (!og_pid)
		og_pid = info->si_pid;
	if (og_pid != info->si_pid && g_power != 7)
	{
		og_pid = 0;
		byte = 0;
		g_power = 7;
	}
	if (signum == SIGUSR2)
		byte += ft_power(2, g_power);
	if (--g_power == -1)
	{
		if (byte == 0)
			kill(info->si_pid, SIGUSR1);
		else
			ft_printf("%c", byte);
		og_pid = 0;
		byte = 0;
		g_power = 7;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
