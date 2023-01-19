/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedrones <jpedrones@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:57:22 by jpedrones         #+#    #+#             */
/*   Updated: 2022/11/04 22:15:23 by jpedrones        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include "error_message.h"

static int	g_bits;

static void	terminate(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

static void	client(int server_pid, char *text)
{
	static char	*msg;
	static int	pid;

	if (text)
		msg = ft_strjoin(text, "\n");
	if (server_pid)
		pid = server_pid;
	if (msg[g_bits / 8] == '\0')
	{
		free(msg);
		terminate(OK_SERVER);
	}
	if (msg[g_bits / 8] & (1 << (g_bits % 8)))
	{
		if (kill(pid, SIGUSR1) == -1)
			terminate(ERR_SERVER_USR1);
	}
	else if (kill(pid, SIGUSR2) == -1)
		terminate(ERR_SERVER_USR2);
}

static void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		g_bits++;
		client(0, 0);
	}
	if (sig == SIGUSR2)
		terminate(ERR_SERVER_UNEXPECTED);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		signal(SIGUSR1, &handler);
		signal(SIGUSR2, &handler);
		client(ft_atoi(argv[1]), argv[2]);
		while (1)
			pause();
	}
	ft_printf("Argument error try:\n");
	ft_printf("\033[0;33m./client <PID> <MESSAGE>\033[0m\n");
}
