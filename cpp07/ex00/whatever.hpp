/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:57:44 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/30 16:05:24 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename T>
T min(T &a, T &b)
{
	if (a > b)
		return (b);
	return (a);
}

template <typename T>
T max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif