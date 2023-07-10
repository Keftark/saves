/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:55:06 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/10 10:46:43 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 97 || str[i] > 122)
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>
int	main(void)
{
	char st[] = "";
	int i = ft_str_is_lowercase(st);
	printf("%d", i);
	if (i == 0)
		printf(" <-- cette chaine n'est pas lowercase");
	else
		printf(" <-- cette chaine est integralement lowercase");

}*/
