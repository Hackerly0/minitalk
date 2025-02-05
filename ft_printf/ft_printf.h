/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalhoora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 01:27:45 by oalhoora          #+#    #+#             */
/*   Updated: 2024/09/14 01:35:09 by oalhoora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char ch);
int	ft_puthexa(unsigned int nbr, char *characters);
int	ft_putnbr(int nbr);
int	ft_putptr(void *ptr);
int	ft_putunsint(unsigned int nbr);
int	ft_putstr(char *str);

#endif
