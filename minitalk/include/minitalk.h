/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:27:28 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/23 08:25:05 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void	ft_putchar(int c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	handler_next(int pid, int i);
void	ft_bzero(void *str, size_t j);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);

#endif
