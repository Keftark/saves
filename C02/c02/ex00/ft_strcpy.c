/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:51:12 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/14 09:12:29 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char	source[] = " ";
	char	*destination;
	int		len;

	len = 0;
	while (source[len])
		len++;
	destination = malloc(len + 1);
	printf("%s\n", ft_strcpy(destination, source));
	printf("%s", destination);
	free(destination);
	return (0);
}*/
