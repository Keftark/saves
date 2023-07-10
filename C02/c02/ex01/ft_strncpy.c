/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:02:22 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/13 10:35:50 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
int	get_count(char *st)
{
	int	cnt = 0;

	while (st[cnt])
		cnt++;
	return cnt;
}

int	main(void)
{
	char str[] = "Salut !";
	char *pstr = str;
	int count_str = get_count(pstr);
	char pdest[25];
	printf("Base = %s\n", pstr);
	printf("Avant = %s\n", pdest);
	ft_strncpy(pdest, str, count_str);
	printf("Apres = %s", pdest);
}*/
