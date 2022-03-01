/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:15:41 by ilahyani          #+#    #+#             */
/*   Updated: 2022/03/01 10:24:23 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int j = 7;

void	handler(int signum)
{
	static int	byte = 0;

/*	if (signum != SIGUSR1 && signum != SIGUSR2)
	{
		j = 7;
		byte = 0;
	}*/
	if (signum == SIGUSR2)
		byte += pow(2, j); //ft_pow
	if (--j == -1)
	{
		write(1, &byte, 1);
		byte = 0;
		j = 7;
	}
}

int main()
{
	printf("%d\n", getpid()); //error if pid is got other chars than digits 
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	//signal(SIGINT, handler);
	while (1)
		pause();
	return (0);
}
