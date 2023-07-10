/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_common.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:14:39 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/20 16:11:37 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"
//#include "libft/ft_itoa.c"
//#include "libft/ft_putstr_fd.c"

int	ft_ptchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_ptperc(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_int(int nb)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(nb);
	i = ft_print_str(str);
	free(str);
	return (i);
}
