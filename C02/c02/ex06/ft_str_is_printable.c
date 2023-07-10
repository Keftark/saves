/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:56:44 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/13 08:59:00 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>
int	main(void)
{
	char	st[] = "comment";
	int	i;

	i = ft_str_is_printable(st);
	if(i == 0)
		printf("Cette chaine n'est pas printable");
	else
		printf("%s <-- Cette chaine est printable", st);
}*/
