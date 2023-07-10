/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:57:46 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/12 16:58:41 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc((i * sizeof(char)) + 1);
	if (!dest)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/*int	main(void)
{
	char	*dest;	
	char	src[] = "Hey";

	dest = ft_strdup(src);
	printf("%s", dest);
	//if (dest == NULL)
	//	puts("NOOOOOOOOOOOOOOOOOOOO");
	free(dest);
}*/
