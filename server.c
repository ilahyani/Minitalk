/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:15:41 by ilahyani          #+#    #+#             */
/*   Updated: 2022/02/27 21:21:23 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

int j = 7;
/*
void	handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "0", 1);
	else
		write(1, "1", 1);
}

*/
void	handler(int signum)
{
	static int	byte = 0;

	if (signum == SIGUSR2)
		byte += pow(2, j);
//	printf("-->%c\n", byte);
	if (--j == -1)
	{
		write(1, &byte, 1);
		byte = 0;
		j = 7;
	}
//	printf("-->%d\n", j);
}

int main()
{
	printf("%d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
