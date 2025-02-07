/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:50:34 by hnisirat          #+#    #+#             */
/*   Updated: 2025/01/25 17:50:39 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_exit(char *str, pid_t pid, int i)
{
	kill(pid, SIGUSR2);
	if (i)
		free(str);
	exit(1);
}

char	*string_join(char *c, char *str, pid_t pid)
{
	static size_t	str_len = 0;
	static size_t	str_capacity = 0;
	char			*new_str;

	if (!str)
	{
		str = malloc(2);
		if (!str)
			free_exit(str, pid, 0);
		str_len = 0;
		str_capacity = 2;
	}
	if (str_len + 2 > str_capacity)
	{
		str_capacity *= 2;
		new_str = ft_realloc(str, str_capacity);
		if (!new_str)
			free_exit(str, pid, 1);
		str = new_str;
	}
	str[str_len++] = *c;
	str[str_len] = '\0';
	return (str);
}

void	printing_and_freeing(char *c, int *j, char **str, pid_t pid)
{
	if (*c == 0)
	{
		if (*str)
		{
			ft_printf ("%s\n", *str);
			free (*str);
		}
		else
			ft_printf("Received an empty message\n");
		kill(pid, SIGUSR2);
		*str = NULL;
		*j = 0;
	}
	else
	{
		*str = string_join(c, *str, pid);
		*j = 0;
		*c = 0;
	}
}

void	handler_sigaction(int signum, siginfo_t *info, void *context)
{
	static char		c = 0;
	static int		counter = 0;
	static pid_t	client_pid = 0;
	static char		*str = NULL;
	pid_t			pid2;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	pid2 = info->si_pid;
	if (client_pid != pid2)
	{
		client_pid = pid2;
		free(str);
		str = NULL;
		c = 0;
		counter = 0;
	}
	if (signum == SIGUSR2)
		c |= (1 << counter);
	counter++;
	if (counter == 8)
		printing_and_freeing(&c, &counter, &str, client_pid);
	if ((kill(pid2, SIGUSR1)) == -1)
		printing_and_freeing(0, &counter, &str, client_pid);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID is: %i\n", getpid());
	sa.sa_sigaction = handler_sigaction;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
