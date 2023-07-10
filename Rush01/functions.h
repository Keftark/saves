/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:48:19 by aramier           #+#    #+#             */
/*   Updated: 2023/03/11 14:48:23 by aramier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	init_tab(int **tab, int o);
void	try_solve(int **tab, int *entry, int o);
void	display_solution(int **tab, int o);

int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		*get_numbers(char *str, int o);
int		check(int ac, char **av, int o);
int		check_double(int **tab, int pos, int num, int o);
int		check_case(int **tab, int pos, int *entry, int o);
int		solve(int **tab, int *entry, int pos, int o);

#endif
