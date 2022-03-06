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

#include "minitalk.h"

int main(int ac, char **av)
{
	int		i;
	int		z;
	size_t	j;
	size_t	size;

	if (ac != 3 || ft_atoi(av[1]) <= 1)
		return (0);
	j = 0;
	size = ft_strlen(av[2]);
	while (j <= size)
	{
		z = 128;
		i = 1;
		while (i < 9)
		{
			if ((z & av[2][j]) == 0)
				kill(ft_atoi(av[1]), SIGUSR1);
			else if ((z & av[2][j]) == z)
				kill(ft_atoi(av[1]), SIGUSR2);
			z = z >> 1;
			i++;
			usleep(500);
		}
		j++;
	}
	return (0);
}
