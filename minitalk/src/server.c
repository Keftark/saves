/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:28:35 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/26 15:28:34 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	set_str(char **str, int i)
{
	if (*str)
		free(*str);
	*str = (char *)malloc(sizeof(char) * i + 1);
	if (!*str)
		return (0);
	return (1);
}

void	ft_end_handler(int *bit, int *i, int *n)
{
	*bit = 0;
	*i = 0;
	*n += 1;
}

int	ft_handler2(int *signal, int *i, int bit, void **s)
{
	(void)*s;
	if (*signal == SIGUSR1)
		*i |= (0x01 << bit);
	bit++;
	return (bit);
}

void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static int	i;
	static int	n;
	static char	*str;

	(void)info;
	bit = ft_handler2(&signal, &i, bit, &s);
	if (bit == 8)
	{
		if (n == 0)
			set_str(&str, i);
		else
		{
			str[n - 1] = i;
			if (i == '\n')
			{
				str[n] = '\0';
				ft_putstr(str);
				n = -1;
			}
			handler_next(info->si_pid, i);
		}
		ft_end_handler(&bit, &i, &n);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sig;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr("\033[91mError: wrong format.\033[0m\n");
		ft_putstr("\033[33mTry: ./server\033[0m\n");
		return (0);
	}
	pid = getpid();
	ft_putstr("\033[94mPID\033[0m \033[96m->\033[0m ");
	ft_putnbr(pid);
	ft_putstr("\n\033[90mWaiting for a message...\033[0m\n");
	sig.sa_sigaction = ft_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}
