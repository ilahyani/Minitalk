/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:02:58 by ilahyani          #+#    #+#             */
/*   Updated: 2022/03/06 15:28:28 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(char c, int pid, int reference)
{
	if ((reference & c) == 0)
		kill(pid, SIGUSR1);
	else if ((reference & c) == reference)
		kill(pid, SIGUSR2);
}

int	main(int ac, char **av)
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
			send_bit(av[2][j], ft_atoi(av[1]), z);
			z = z >> 1;
			i++;
			usleep(500);
		}
		j++;
	}
	return (0);
}
