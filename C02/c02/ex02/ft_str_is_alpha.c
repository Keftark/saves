/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:31:25 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/10 10:40:01 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 65 || (c > 90 && c < 97) || c > 122)
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>
int	main(void)
{
	char	st[] = "azheyKH";
	int i = ft_str_is_alpha(st);

	printf("%s\n", st);
	printf("%d", i);
	if (i == 0)
		printf(" <-- cette chaine n'est pas alphabetique");
	else if (i == 1)
		printf(" <-- cette chaine est bien alphabetique");
}*/
