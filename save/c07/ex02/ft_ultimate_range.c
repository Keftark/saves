/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:31:18 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/15 09:36:50 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	if ((tab = (int*)malloc(sizeof(int) * (max - min))) == NULL)
		return (-1);
	i = 0;
	while (i < (max - min))
	{
		tab[i] = i + min;
		i++;
	}
	*range = tab;
	free(tab);
	return (i);
}

/*int	main(void)
{
	int i = 0;
	int t;
	int *ta = &t;
	int **tab = &ta;
	
	i = ft_ultimate_range(tab, 8, 5);
	printf("Taille du tableau = %d", i);
}*/
