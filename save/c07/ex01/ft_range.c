/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:53:29 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/14 17:12:53 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*rng;
	int	i;
	int	t;

	if (min >= max)
		return (NULL);
	t = max - min;
	rng = (int *)malloc(sizeof(int) * t);
	if (!rng)
		return (NULL);
	i = 0;
	while (i < t)
	{
		rng[i] = i + min;
		i++;
	}
	return (rng);
}

/*int	chartoint(char *c)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	if (c[i] < '0' || c[i] > '9')
		return (0);
	r = c[0] - 48;
	return (r);
}

int	main(int argc, char *argv[])
{
	int	*rang;
	int	min;
	int	max;
	int	i = 0;

	if (argc != 3)
		return (0);
	min = chartoint(argv[1]);
	max = chartoint(argv[2]);
	max = 20;
	rang = ft_range(min, max);
	while(i < max - min)
	{
		if (rang[i] == 0)
			return (0);
		printf("%d ", rang[i]);
		i++;
	}
	free(rang);
}*/
