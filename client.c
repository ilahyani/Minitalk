/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:02:58 by ilahyani          #+#    #+#             */
/*   Updated: 2022/03/01 09:45:57 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int	i;
	int	j;
	int	z;

	if (ac != 3)
		return (0);
	j = 0;
	while (av[2][j])
	{
		z = 128;
		i = 1;
		while (i < 9)
		{
			if ((z & av[2][j]) == 0)
				kill(atoi(av[1]), SIGUSR1);
			else if ((z & av[2][j]) == z)
				kill(atoi(av[1]), SIGUSR2);
			z = z >> 1;
			i++;
			usleep(500);
		}
		j++;
	}
	return (0);
}
