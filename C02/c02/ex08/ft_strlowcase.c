/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:21:34 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/10 10:51:20 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*s;
	int		i;

	s = str;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] > 64 && s[i] < 91)
			s[i] += 32;
		i++;
	}
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	char	st[] = "yoOoO";

	printf("%s", ft_strlowcase(st));
}*/
