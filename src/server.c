/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedrones <jpedrones@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:57:17 by jpedrones         #+#    #+#             */
/*   Updated: 2022/11/04 22:15:17 by jpedrones        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include "error_message.h"

static int	g_client_pid;

static void	terminate(char *str)
{
	ft_printf("%s\n", str);
	kill(g_client_pid, SIGUSR2);
	exit(1);
}

static void	get_bit(int bin)
{
	static char	c;
	static int	i;

	c += (bin << i++);
	if (i == 8)
	{
		ft_putchar(c);
		c = 0;
		i = 0;
	}
	if (kill(g_client_pid, SIGUSR1) == -1)
		terminate(ERR_CLIENT_USR1);
}

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	if (info->si_pid)
		g_client_pid = info->si_pid;
	if (sig == SIGUSR1)
		get_bit(1);
	if (sig == SIGUSR2)
		get_bit(0);
	(void)ucontext;
}

int	main(void)
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_printf("\033[0;36mPID: \033[0m%d\n", getpid());
	while (1)
		pause();
}
