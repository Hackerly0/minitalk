/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalhoora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:31:11 by oalhoora          #+#    #+#             */
/*   Updated: 2024/09/14 15:42:10 by oalhoora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	after_checking(int nbr, int *count)
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

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		after_checking(nbr * -1, &i);
		i++;
	}
	else
		after_checking(nbr, &i);
	return (i);
}
