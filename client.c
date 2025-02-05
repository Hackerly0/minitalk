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

static volatile	sig_atomic_t ack = 0;

static void	send_bits(unsigned long val, int bits, int pid)
{
	int	i;

	i = -1;
	while (++i < bits)
	{
		if ((val>>i & 1)==1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{ 
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		while (ack == 0)
			;
		ack = 0;
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
		ack = 1;
	else if (signum == SIGUSR2)
		ft_printf("Message Recieved!");
}

static int	valid_pid(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
		{
			perror("Invalid PID!");
			exit(1);
		}
	}
	i = ft_atoi(s);
	if (i <= 0 || (kill(i, 0)) != 0)
	{
		perror("Invalid PID!");
		exit(1);
	}
	return (i);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3 || !valid_pid(argv[1]))
		return (1);
	sa.sa_handler = ack_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_str(argv[2], ft_atoi(argv[1]));
	return (0);
}
