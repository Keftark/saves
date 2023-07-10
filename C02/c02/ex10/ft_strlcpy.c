/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:56:24 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/14 09:38:14 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (!src || !dest)
		return (0);
	while (src[i] != '\0' && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	unsigned int u = 6;
	char st[] = "coucoucoudd";
	char *pdest;

	pdest = malloc(u + 1);
	printf("Base: %s\n", st);
	//printf("Avant: %s\n", pdest);
	printf("On reduit a %d caracteres, contre %d au debut\n", 
		u, ft_strlcpy(pdest, st, u));
	printf("Apres: %s", pdest);
	free(pdest);
}*/
