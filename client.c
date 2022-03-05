/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:02:58 by ilahyani          #+#    #+#             */
/*   Updated: 2022/03/05 18:48:57 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	handler(int signum)
{
	printf("Your Message Has Been Received Successfully\n");
}

int main(int ac, char **av)
{
	int	i;
	int	j;
	int	z;
	size_t size;

	if (ac != 3 || av[1] <= 1)
		return (0);
	signal(SIGUSR1, handler);
	j = 0;
	size = strlen (av[2]);
	while (j <= size)
	{
		z = 128;
		i = 1;
		while (i < 9)
		{
			if ((z & av[2][j]) == 0)
				kill(atoi(av[1]), SIGUSR1); //error if pid is got other chars than digits 
			else if ((z & av[2][j]) == z)
				kill(atoi(av[1]), SIGUSR2); // ft_atoi
			z = z >> 1;
			i++;
			usleep(500);
		}
		j++;
	}
	return (0);
}
