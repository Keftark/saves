/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:25:30 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/20 16:12:01 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "../libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_ptchar(int c);
int	ft_ptperc(void);
int	ft_print_str(char *str);
int	ft_print_int(int nb);
int	ft_printhex(unsigned int val, const char format);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_unsigned(unsigned int u);

#endif
