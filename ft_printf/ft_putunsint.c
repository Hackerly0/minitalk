/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalhoora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:45:13 by oalhoora          #+#    #+#             */
/*   Updated: 2024/09/14 20:10:11 by oalhoora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static void	after_checking(unsigned int nbr, int *count)
{
	char	c;

	if (nbr != 0)
	{
		c = (nbr % 10) + '0';
		after_checking(nbr / 10, count);
		write(1, &c, 1);
		(*count)++;
	}
}

int	ft_putunsint(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 4294967295)
	{
		write(1, "4294967295", 10);
		return (10);
	}
	else if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		after_checking(nbr, &i);
	return (i);
}
