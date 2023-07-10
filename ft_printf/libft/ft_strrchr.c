/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:48:42 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/15 11:19:00 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;
	char			*last_occurence;

	last_occurence = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			last_occurence = (char *)&str[i];
		i++;
	}
	if ((char)c == str[i])
		return ((char *)&str[i]);
	return (last_occurence);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%s", ft_strrchr("helicoptere", 'c'));
}*/
