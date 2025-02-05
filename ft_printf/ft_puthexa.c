/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalhoora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:45:07 by oalhoora          #+#    #+#             */
/*   Updated: 2024/09/14 18:44:33 by oalhoora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	after_checking(unsigned int nbr, char *characters, int *count)
{
	char	c;

	if (nbr != 0)
	{
		c = characters[nbr % 16];
		after_checking(nbr / 16, characters, count);
		write(1, &c, 1);
		(*count)++;
	}
}

int	ft_puthexa(unsigned int nbr, char *characters)
{
	int	i;

	i = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		after_checking(nbr, characters, &i);
	return (i);
}
