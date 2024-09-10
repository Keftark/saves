/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:00:28 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/30 09:58:40 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data;

    data->str = "this is a string";
    data->nbr = 42;
	std::ostringstream oss;
	oss << Serializer::deserialize(Serializer::serialize(data))->nbr;
	std::string nbrAsString = oss.str();

    std::cout << ToColor(("data->str: " + Serializer::deserialize(Serializer::serialize(data))->str).c_str(), Colors::Green, Colors::Yellow) << std::endl;
    std::cout << ToColor(("data->nbr: " + nbrAsString).c_str(), Colors::Yellow, Colors::Orange) << std::endl;

    delete data;
}
