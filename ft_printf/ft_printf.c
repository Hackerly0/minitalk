/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalhoora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:39:31 by oalhoora          #+#    #+#             */
/*   Updated: 2024/09/14 01:26:56 by oalhoora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	direction(char type, va_list args)
{
	int	i;

	i = 0;
	if (type == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (type == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (type == 'p')
		i = ft_putptr(va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		i = ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		i = ft_putunsint(va_arg(args, unsigned int));
	else if (type == 'x')
		i = ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		i = ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else
	{
		write(1, "%", 1);
		return (1);
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		s;

	va_start(args, str);
	i = 0;
	s = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			s += direction(str[++i], args);
		else
			s += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (s);
}

//#include <stdio.h>
//#include <limits.h>
/*
int	main()
{
	int	i;
	int	j;

	i = ft_printf(" %i \n", 1);
	j = printf(" %i \n", 1);
	printf("%i %i\n", i, j);
	i = ft_printf(" %i \n", 9);
        j = printf(" %i \n", 9);
	printf("%i %i\n", i, j);
	i = ft_printf(" %i \n", 100);
        j = printf(" %i \n", 100);
	printf("%i %i\n", i, j);
	i = ft_printf(" %i \n", 101);
        j = printf(" %i \n", 101);
	printf("%i %i\n", i, j);
	i = ft_printf(" %i \n", -10);
        j = printf(" %i \n", -10);
	printf("%i %i\n", i, j);
	i = ft_printf(" %i \n", -11);
        j = printf(" %i \n", -11);
	printf("%i %i\n", i, j);
	i = ft_printf(" %i \n", -534614);
        j = printf(" %i \n", -534614);
	printf("%i %i\n", i, j);
}*/
/*
int	main()
{
	int	i;
	int	j;

	i = ft_printf(" %x \n", 0);
	j = printf(" %x \n", 0);
	printf("%i %i\n", i, j);
	i = ft_printf(" %x \n", LONG_MIN);
        j = printf(" %x \n", LONG_MIN);
        printf("%i %i\n", i, j);
}*/
