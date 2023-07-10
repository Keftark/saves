/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:44:41 by aramier           #+#    #+#             */
/*   Updated: 2023/04/13 16:32:44 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

int	check_double(int **tab, int pos, int num, int o)
{
	int	i;

	i = -1;
	while (++i < pos / o)
		if (tab[i][pos % o] == num)
			return (1);
	i = -1;
	while (++i < pos % o)
		if (tab[pos / o][i] == num)
			return (1);
	return (0);
}

int	solve(int **tab, int *entry, int pos, int o)
{
	int	size;

	if (pos == o * o)
		return (1);
	size = 0;
	while (++size <= o)
	{
		if (check_double(tab, pos, size, o) == 0)
		{
			tab[pos / o][pos % o] = size;
			if (check_case(tab, pos, entry, o) == 0)
			{
				if (solve(tab, entry, pos + 1, o) == 1)
					return (1);
			}
			else
				tab[pos / o][pos % o] = 0;
		}
	}
	return (0);
}

void	display_solution(int **tab, int o)
{
	int	i;
	int	j;

	i = -1;
	while (++i < o)
	{
		j = -1;
		while (++j < o)
		{
			ft_putnbr(tab[i][j]);
			if (j < o - 1)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	check_total(char *cnt)
{
	int	i;
	int	o;

	o = 1;
	i = ft_strlen(cnt) / 2 + 1;
	while (++o < 10)
		if (o * 4 == i)
			return (o);
	ft_putstr("Not the correct amount of numbers");
	return (0);
}

int	main(int argc, char **argv)
{
	int	**tab;
	int	*entry;
	int	o;
	int	z;

	z = -1;
	o = check_total(argv[1]);
	if (o == 0)
		return (0);
	entry = malloc(o * o * 4);
	tab = malloc((o * o) * 4);
	while (++z < o)
		tab[z] = malloc(o);
	init_tab(tab, o);
	if (check(argc, argv, o) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	entry = get_numbers(argv[1], o);
	try_solve(tab, entry, o);
	o = 0;
	while (tab[o])
	{
		free(tab[o]);
		o++;
	}
	free(entry);
	free(tab);
	return (0);
}
