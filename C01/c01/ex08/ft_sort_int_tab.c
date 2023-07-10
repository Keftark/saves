/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:10 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/17 10:01:54 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	s;

	s = *b;
	*b = *a;
	*a = s;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (i + j < size)
		{
			if (tab[i + j] < tab[i])
				ft_swap(&tab[i], &tab[i + j]);
			j++;
		}
		i++;
	}
}

/*#include <stdlib.h>
int	main()
{
	int	*t;
	int	i;

	t = (int*)malloc(8 * sizeof(int));
	t[0] = 7;
	t[1] = 2;
	t[2] = 5;
	t[3] = 1;
	t[4] = 8;
	t[5] = 3;
	t[6] = 6;
	t[7] = 4;
	ft_sort_int_tab(t, 8);
	i = 0;
	while (i < 8)
	{
		printf("%d ", t[i]);
		i++;
	}
	free(t);
}*/
