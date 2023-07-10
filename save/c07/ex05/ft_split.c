/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:52:54 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/16 10:55:58 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	count_words(char *str, char *charset)
{
	int	i;
	int	j;

	while (*str)
	{
		j = 0;
		while (charset[j])
		{
			if (*str == charset[j])
				i++;
			j++;
		}

	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc((i * sizeof(char)) + 1);
	if (!dest)
		return (NULL);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;


}

int	main(int argc, char *argv[])
{
	char	*set = " ";

	argc = 1;
	ft_split(argv[1], set);
}
