/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:35:09 by hnisirat          #+#    #+#             */
/*   Updated: 2025/01/26 21:35:30 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include "ft_printf/ft_printf.h"
#include "ft_printf/Libft/libft.h"

static volatile sig_atomic_t	g_ack = 0;

static void	send_bits(unsigned long val, int bits, int pid)
{
	int	i;

	i = -1;
	while (++i < bits)
	{
		if ((val >> i & 1) == 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		while (g_ack == 0)
			;
		g_ack = 0;
	}
}

static void	send_str(char *str, int pid)
{
	while (*str)
		send_bits(*str++, 8, pid);
	send_bits(0, 8, pid);
}

void	ack_handler(int signum)
{
	if (signum == SIGUSR1)
		g_ack = 1;
	else if (signum == SIGUSR2)
		ft_printf("Message Recieved!\n");
}

static int	valid_pid(char *s)
{
	int	i;

	if (!s)
	{
		ft_printf("No PID!\n");
		exit(1);
	}
	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
		{
			errno = EINVAL;
			perror("Invalid PID!");
			exit(1);
		}
	}
	i = ft_atoi(s);
	if (i <= 0 || (kill(i, 0)) != 0)
	{
		errno = EINVAL;
		perror("Invalid PID!");
		exit(1);
	}
	return (i);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					i;

	i = 0;
	i = valid_pid(argv[1]);
	if (argc != 3 || !i)
	{
		errno = EINVAL;
		perror("Invalid number of arguments!");
		exit(1);
	}
	sa.sa_handler = ack_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_str(argv[2], i);
	return (0);
}
