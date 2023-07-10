/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:45:01 by aramier           #+#    #+#             */
/*   Updated: 2023/04/13 16:29:09 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

int	check(int ac, char **av, int o)
{
	if (ac != 2)
		return (1);
	if (ft_strlen(av[1]) != o * 4 * 2 - 1)
		return (1);
	return (0);
}

int	*get_numbers(char *str, int o)
{
	int	i;
	int	j;
	int	*tab;

	tab = malloc(sizeof(int) * (o * o));
	i = -1;
	j = 0;
	while (str[++i] != '\0')
		if (str[i] >= '0' && str[i] <= '9')
			tab[j++] = ft_atoi(str + i);
	return (tab);
}

void	init_tab(int **tab, int o)
{
	int	i;
	int	j;

	i = 0;
	while (i < o)
	{
		j = 0;
		while (j < o)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	try_solve(int **tab, int *entry, int o)
{
	if (solve(tab, entry, 0, o) == 1)
		display_solution(tab, o);
	else
		ft_putstr("Did not find any solutions\n");
}
