/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:34:08 by cpothin           #+#    #+#             */
/*   Updated: 2023/05/18 14:53:03 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (NULL);
	else if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			&& (str[i - 1] < '0' || (str[i - 1] > '9' && str[i - 1] < 'A')
				|| (str[i - 1] > 'Z' && str[i - 1] < 'a')
				|| str[i - 1] > 'z'))
		{
			str[i] -= 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
	return (str);
}

int	main(void)
{
	char	ch[] = "CecI eST un tESt";

	printf("Avant = %s\n", ch);
	printf("Apres = %s\n", ft_strcapitalize(ch));
}
