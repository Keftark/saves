/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:19:37 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/10 10:48:59 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	u;

	i = 0;
	u = 1;
	while (str[i] != '\0')
	{
		if (str[i] < 65 || str[i] > 90)
			u = 0;
		i++;
	}
	return (u);
}

/*#include <stdio.h>
int	main(void)
{
	char	st[] = "HG";
	int i = ft_str_is_uppercase(st);
	printf("%d", i);
	if (i == 0)
		printf(" <-- cette chaine n'est pas uppercase");
	else
		printf(" <-- cette chaine est integralement en uppercase");
}*/
