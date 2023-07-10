/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:48:28 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/10 10:42:44 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>
int	main(void)
{
	char	st[] = "123I";
	int i = ft_str_is_numeric(st);

	printf("%d", i);
	if (i == 0)
		printf(" <-- cette chaine n'est pas numerique");
	else
		printf(" <-- cette chaine est numerique");
}*/
