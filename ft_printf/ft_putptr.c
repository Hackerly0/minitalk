/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalhoora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:42:43 by oalhoora          #+#    #+#             */
/*   Updated: 2024/09/14 15:44:18 by oalhoora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include "ft_printf.h"

static void	after_checking(long unsigned nbr, char *digits, int *count)
{
	char	c;

	if (nbr != 0)
	{
		c = digits[nbr % 16];
		after_checking(nbr / 16, digits, count);
		write(1, &c, 1);
		(*count)++;
	}
}

int	ft_putptr(void *ptr)
{
	int	i;

	i = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		after_checking((long unsigned)ptr, "0123456789abcdef", &i);
	}
	return (i + 2);
}
/*
int	main()
{
	char	*s = NULL;
	int		i;

	i = 25;
	ft_putptr();
	printf("\n%p\n", s);
	ft_putptr(&i);
	printf("\n%p\n", &i);
}*/
