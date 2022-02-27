#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
	int	i;
	int	j;
	int	z;

	if (ac != 3)
		return (0);
	j = 0;
	while (j < strlen(av[2]))
	{
		z = 128;
		i = 1;
		while (i < 9)
		{
			if ((z & av[2][j]) == 0)
			{
				printf ("0");
				kill(atoi(av[1]), SIGUSR1);
			}
			else if ((z & av[2][j]) == z)
			{
				printf ("1");
				kill(atoi(av[1]), SIGUSR2);
			}
			z = z >> 1;
			i++;
		}
		j++;
	}
	return (0);
}
