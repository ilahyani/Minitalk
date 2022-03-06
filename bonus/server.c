/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:15:41 by ilahyani          #+#    #+#             */
/*   Updated: 2022/03/05 18:48:20 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int j = 7;

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	byte = 0;
	static int og_pid;

	if (!og_pid)
		og_pid = info->si_pid;
	if (og_pid != info->si_pid && j != 7)
	{
		og_pid = 0;
		byte = 0;
		j = 7;
	}
	if (signum == SIGUSR2)
		byte += pow(2, j); //ft_pow
	if (--j == -1)
	{
		if (byte == 0)
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &byte, 1);
		og_pid = 0;
		byte = 0;
		j = 7;
	}
}

int main()
{
	struct sigaction sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	printf("%d\n", getpid()); //ft_printf
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
