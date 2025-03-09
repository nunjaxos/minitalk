#include "talk.h"

void    send_bit(pid_t pid, int bit)
{
        if (bit == 0)
                kill(pid, SIGUSR1);
        else
                kill(pid, SIGUSR2);
}

void    convert_str_to_bit_and_send(pid_t pid, char *str)
{
        int     i;
        int bit;
        unsigned char character;
        int current_bit;

        i = 0;
        while(str[i])
        {
                character = str[i];
                bit = 128;
                while (bit)
                {
                        if (character & bit)
                                current_bit = 1;
                        else
                                current_bit = 0;
                        send_bit(pid, current_bit);
                        usleep(150);
                        bit /= 2;
                }
                i++;
        }
}

int main(int ac, char **av)
{
        pid_t   server_pid;

        server_pid = atoi(av[1]);
	
        if (ac != 3)
        {
		printf("Invalid input\n");
                exit(1);
        }
	if (kill(server_pid, 0) == -1 && errno == ESRCH)
	{
    		printf("Invalid pid\n");
    		exit(1);
	}	
        convert_str_to_bit_and_send(server_pid, av[2]);
        return (0);
}

