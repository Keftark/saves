/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:17:24 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/08 09:50:56 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

/*#include <stdio.h>
int main(void){
int a = 1;
int b = 2;
printf("Avant: %d\n", a);
ft_swap(&a, &b);
printf("Apres: %d", a);
return (0);
}*/
