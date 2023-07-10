/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:45:29 by aramier           #+#    #+#             */
/*   Updated: 2023/03/12 15:19:34 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int **tab, int pos, int *entry, int o)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (pos / o == o - 1)
	{
		while (i < o)
		{
			if (tab[i][pos % o] > max)
			{
				max = tab[i][pos % o];
				count++;
			}
			i++;
		}
		if (entry[pos % o] != count)
			return (1);
	}
	return (0);
}

int	check_row_right(int **tab, int pos, int *entry, int o)
{
	int	i;
	int	max_size;
	int	visible_towers;

	i = o;
	max_size = 0;
	visible_towers = 0;
	if (pos % o == o - 1)
	{
		while (--i >= 0)
		{
			if (tab[pos / o][i] > max_size)
			{
				max_size = tab[pos / o][i];
				visible_towers++;
			}
		}
		if (entry[o * 3 + pos / o] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_col_down(int **tab, int pos, int *entry, int o)
{
	int	i;
	int	max;
	int	count;

	i = o - 1;
	max = 0;
	count = 0;
	if (pos / o == o - 1)
	{
		while (i >= 0)
		{
			if (tab[i][pos % o] > max)
			{
				max = tab[i][pos % o];
				count++;
			}
			i--;
		}
		if (entry[o + pos % o] != count)
			return (1);
	}
	return (0);
}

int	check_row_left(int **tab, int pos, int *entry, int o)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (pos % o == o - 1)
	{
		while (i < o)
		{
			if (tab[pos / o][i] > max)
			{
				max = tab[pos / o][i];
				count++;
			}
			i++;
		}
		if (entry[o * 2 + pos / o] != count)
			return (1);
	}
	return (0);
}

int	check_case(int **tab, int pos, int *entry, int o)
{
	if (check_row_left(tab, pos, entry, o) == 1)
		return (1);
	if (check_row_right(tab, pos, entry, o) == 1)
		return (1);
	if (check_col_down(tab, pos, entry, o) == 1)
		return (1);
	if (check_col_up(tab, pos, entry, o) == 1)
		return (1);
	return (0);
}
