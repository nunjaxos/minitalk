#include "talk.h"

void handle_signal(int sig, siginfo_t *info, void *content)
{
	static unsigned char received_char;
	static int bit_count;

	if (sig == SIGUSR1)
	    received_char = received_char << 1;
	else if (sig == SIGUSR2)
        	received_char = (received_char << 1) | 1;
	bit_count++;
	
	if (bit_count == MAX_BITS)
    	{
        	if (received_char == '\0')
            		write(1, "\n", 1);
        	else
            		write(1, &received_char, 1);
        	received_char = 0;
        	bit_count = 0;
    	}
}

int main(void)
{
	struct	sigaction	sa;

	printf("%d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
        	pause();
	
	return (0);
}
