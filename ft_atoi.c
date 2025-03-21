/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:29:09 by abhmidat          #+#    #+#             */
/*   Updated: 2025/03/17 02:04:57 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "talk.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	r;
	int		c;

	i = 0;
	r = 0;
	c = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			c = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = r * 10 + str[i] - 48;
		i++;
	}
	return (r * c);
}
