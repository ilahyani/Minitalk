#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "0", 1);
	else
		write(1, "1", 1);
}
int main()
{
	struct sigaction sa = {0};

	sa.sa_handler = &handler;
	printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
