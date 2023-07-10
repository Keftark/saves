/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:06:41 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/10 10:50:55 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*s;
	int		i;

	s = str;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] > 96 && s[i] < 123)
			s[i] -= 32;
		i++;
	}
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	char	st[] = "adsfFGHD";

	ft_strupcase(st);
	printf("%s", st);
}*/
