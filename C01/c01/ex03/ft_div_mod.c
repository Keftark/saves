/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:13:45 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/08 09:57:31 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*#include <stdio.h>
int	main(void)
{
	int i1 = 10;
	int i2 = 2;
	int a1 = 0, a2 = 0;
	int *p1 = &a1;
	int *p2 = &a2;

	ft_div_mod(i1, i2, p1, p2);
	printf("%d divise par %d = %d\n", i1, i2, *p1);
	printf("%d modulo de %d = %d", i1, i2, *p2);
	return (0);
}*/
