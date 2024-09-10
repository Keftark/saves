/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:06:38 by cpothin           #+#    #+#             */
/*   Updated: 2024/05/30 10:59:19 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &a)
{
	*this = a;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &a)
{
	(void)a;
	return (*this);
}

void ScalarConverter::convert(std::string str)
{
	std::string specialTypes[6] = {
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};
	std::string toChar = "";
	int toInt = 0;
	float toFloat = 0;
	double toDouble = 0;

	//if is a char
	if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0])) {
		toChar = str[0];
		std::cout << RGB(0, 230, 230) << "char: " << toChar << std::endl;
		std::cout << RGB(Colors::LightTeal) << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << RGB(Colors::Teal) << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << RGB(Colors::DarkTeal) << "double: " << static_cast<double>(toChar[0]) << ".0" << RESET << std::endl;
		return ;
	}

	//if it is a number
	toInt = std::atoi(str.c_str());

	// check if it is float or int / double
	if (str[str.length() - 1] == 'f')
	{
		toFloat = std::atof(str.c_str());
		toDouble = static_cast<double>(toFloat);
	}
	else
	{
		toDouble = std::atof(str.c_str());
		toFloat = static_cast<float>(toDouble);
	}

	for (int i = 0; i < 6; ++i)
	{
		if (str == specialTypes[i])
		{
			toChar = "imposible";
			break;
		}
	}
	if (toChar == "" && std::isprint(toInt))
	{
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	}
	else if (toChar == "")
		toChar = RGB2(Colors::Red, Colors::Black) + "Non displayable" + RESET;
	std::cout << RGB(0, 230, 230) << "char: " << toChar << std::endl;
	if (toChar == "imposible")
		std::cout << RGB2(Colors::Red, Colors::Black) << "int: imposible" << std::endl;
	else
		std::cout << RGB(Colors::LightTeal) << "int: " << toInt << std::endl;
	if (toChar == "imposible" && toFloat == 0)
	{
		std::cout << RGB2(Colors::Red, Colors::Black) << "float: imposible" << std::endl;
		std::cout << RGB2(Colors::Red, Colors::Black) << "double: imposible" << RESET << std::endl;
	}
	else
	{
		if (toChar != "imposible" && toFloat - static_cast<int>(toFloat) == 0)
		{
			std::cout << RGB(Colors::Teal) << "float: " << toFloat << ".0f" << std::endl;
			std::cout << RGB(Colors::DarkTeal) << "double: " << toDouble << ".0" << RESET << std::endl;
		}
		else
		{
			std::cout << RGB(Colors::Teal) << "float: " << toFloat << "f" << std::endl;
			std::cout << RGB(Colors::DarkTeal) << "double: " << toDouble << RESET << std::endl;
		}
	}
}
