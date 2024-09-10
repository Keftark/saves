/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:07:04 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/30 17:47:55 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *a, unsigned int length, void(*f)(T const&))
{
	for (unsigned int i = 0; i < length; i++)
		f(a[i]);
}

#endif