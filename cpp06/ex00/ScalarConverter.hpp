/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:06:35 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/29 14:25:31 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include "Colors.hpp"

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &a);
		ScalarConverter &operator=(const ScalarConverter &a);
	public:
		~ScalarConverter();
		static void convert(std::string str);
};

#endif