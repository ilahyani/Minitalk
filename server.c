#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handlerr(int signum)
{
	if (signum == SIGUSR1)
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
}
int main()
{
	struct sigaction sa = {0};

	sa.sa_handler = &handlerr;
	printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1);
	return (0);
}
