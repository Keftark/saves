/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:48:07 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/23 15:09:13 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	main(int argc, char *argv[])
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (++j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) < 0)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
		}
	}
	i = 0;
	while (argv[++i])
	{
		if (i != 1)
			write(1, "\n", 1);
		print_str(argv[i]);
	}
}
