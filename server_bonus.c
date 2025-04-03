/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:13:22 by hakader           #+#    #+#             */
/*   Updated: 2025/04/03 19:10:34 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	reset_int(int *bits)
{
	int	i;

	i = 0;
	while (i < 8)
		bits[i++] = 0;
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	bits[8] = {0};
	static int	i;
	static int	last_pid;

	int (result), (j);
	(void)context;
	if (last_pid != info->si_pid)
	{
		(reset_int(bits)), (last_pid = info->si_pid);
		i = 0;
	}
	if (sig == SIGUSR1)
		bits[i] = 1;
	else if (sig == SIGUSR2)
		bits[i] = 0;
	i++;
	if (i == 8)
	{
		result = 0;
		j = 0;
		while (j < 8)
			result = result * 2 + bits[j++];
		write(1, &result, 1);
		i = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sig;

	(void)av;
	if (ac != 1)
		(write(2, "\n", 1)), (exit (1));
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		;
}
