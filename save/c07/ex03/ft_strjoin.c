/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:37:57 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/18 16:20:02 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_total_length(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	siz;
	int	len;

	i = 0;
	len = 0;
	siz = 0;
	while (siz < size)
	{
		j = -1;
		while (strs[i][++j])
		{
			len++;
		}
		i++;
		j = -1;
		if (siz < size)
			while (sep[++j])
				len++;
		siz++;
	}
	printf("Total length = %d\n", len);
	return (len);
}

char	*ft_strcat(char *st1, char *st2)
{
	int	i;
	int	j;

	i = 0;
	while (st1[i])
		i++;
	j = -1;
	while (st2[++j])
		st1[i + j] = st2[j];
	st1[i + j] = '\0';
	return (st1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*n;
	int		siz;

	if (size == 0)
	{
		n = malloc(sizeof(char));
		*n = 0;
		return (n);
	}
	n = (char *)malloc(sizeof(char) * ft_total_length(size, strs, sep) + 1);
	if (!n)
		return (NULL);
	siz = 0;
	*n = '\0';
	while (siz < size)
	{
		ft_strcat(n, strs[siz]);
		if (siz < size - 1)
			ft_strcat(n, sep);
		siz++;
	}
	printf("%s", n);
	return (n);
}

/*int	main(int argc, char **argv)
{
	char	*sp = " ";
	char	*str;

	str = *argv;
//	argc = 0;
	str = ft_strjoin(argc, argv, sp);
	free(str);
}*/
