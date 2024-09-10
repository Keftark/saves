/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:44:06 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/30 09:59:09 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <string>

struct	Data
{
	unsigned int nbr;
	std::string str;
};

class Serializer
{
	public:
		static Data* deserialize(uintptr_t raw);
		static uintptr_t serialize(Data* ptr);
};

#endif