/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:06:16 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/17 09:14:04 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	rev;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		rev = tab[i];
		tab[i] = tab[j];
		tab[j] = rev;
		i++;
		j--;
	}
}

/*int	main(void)
{
	int t[5] = {1, 2, 3, 4, 5};
	int i = 0;

	while (i < 5)
	{
		printf("%d", t[i]);
		i++;
	}
	ft_rev_int_tab(t, 5);
	i = 0;
	while (i < 5)
	{
		printf("%d", t[i]);
		i++;
	}
}*/
