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

int	ft_putstr(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main()
{
	char	*s = NULL;
	char	l[] = "\0";
	int	i;

	i = 0;
	ft_putstr(s);
	i = printf("\n%s\n", s);
	ft_putstr(l);
	printf("\n%s\n", l);
	printf("%i\n", i);
}*/
