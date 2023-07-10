/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:38:44 by cpothin           #+#    #+#             */
/*   Updated: 2023/05/15 16:10:46 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
/*#include "ft_print_common.c"
#include "ft_print_hex.c"
#include "ft_print_ptr.c"
#include "ft_print_unsigned.c"
#include "../libft/libft.h"
#include "../libft/ft_itoa.c"
#include "../libft/ft_putstr_fd.c"
#include "../libft/ft_strlen.c"
#include "../libft/ft_calloc.c"
#include "../libft/ft_bzero.c"*/

static int	format(va_list args, const char c)
{
	int	l;

	l = 0;
	if (c == 'c')
		l = ft_ptchar(va_arg(args, int));
	else if (c == 's')
		l = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		l = ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		l = ft_print_int(va_arg(args, int));
	else if (c == 'u')
		l = ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		l = ft_printhex(va_arg(args, unsigned int), c);
	else if (c == '%')
		l = ft_ptperc();
	return (l);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		l;

	i = 0;
	l = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			l += format(args, str[i + 1]);
			i++;
		}
		else
			l += ft_ptchar(str[i]);
		i++;
	}
	va_end(args);
	return (l);
}

/*int	main(void)
{
//	int	i = 0;	
//	int	o = 123456789;
//	char	*str = "CoUcOu";
//	ft_printf(" %p %p \n", 0, 0);
	printf(" %p %p \n", 0, 0);
//	ft_printf("%u - %p - %x - %s - %i\n", o, (void *)&i, o, str, i);
//	printf("%u - %p - %x - %s - %i", o, (void *)&i, o, str, i);
}*/
