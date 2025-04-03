/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:57:03 by hakader           #+#    #+#             */
/*   Updated: 2025/04/03 19:09:14 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	char	c;
	int		mod;

	mod = 1;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (n / mod >= 10)
		mod *= 10;
	while (mod > 0)
	{
		c = (n / mod) + 48;
		write(1, &c, 1);
		n %= mod;
		mod /= 10;
	}
}
