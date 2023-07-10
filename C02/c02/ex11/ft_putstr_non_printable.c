/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:54:05 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/13 16:54:38 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printhex(int nb)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb > 16)
	{
		printhex(nb / 10);
		printhex(nb % 10);
	}
	else
		write(1, &hex[nb], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	if (str[0])
	{
		while (str[i])
		{
			if (str[i] < 32 || str[i] > 126)
			{
				write(1, "\\", 1);
				if (str[i] < 16)
					write(1, "0", 1);
				printhex(str[i]);
			}
			else
				write(1, &str[i], 1);
			i++;
		}
	}
}

/*int	main(void)
{
	char st[] = "Un chasseur sachant chasser\ndoit savoir chasser sans son chien.";

	ft_putstr_non_printable(st);
}*/
