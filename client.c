#include <signal.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	kill(atoi(av[1]), SIGUSR1);
//	kill(atoi(av[1]), SIGUSR2);
//	kill(atoi(av[1]), SIGINT);
}
