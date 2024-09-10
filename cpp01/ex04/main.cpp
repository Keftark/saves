/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:52:03 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/27 11:28:17 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "Colors.hpp"

void	process_lines(std::ifstream &inFile, std::string fileName, std::string in, std::string out)
{
	std::string		line;
	std::ofstream	outFile((fileName + ".replace").c_str());
	
	while (std::getline(inFile, line))
	{
		size_t	pos = line.find(in);
		while (pos != std::string::npos)
		{
			line.erase(pos, in.length());
			line.insert(pos, out);
			pos = line.find(in);
		}
		outFile << line << std::endl;
	}
	std::cout << LIME << "File processed successfully!" << RESET << std::endl;
}

int main(int argc, char *argv[])
{
	std::ifstream	inFile;

	if (argc != 4)
	{
		std::cerr << Rainbow("Error!\n\tThe parameters must be") << " <" TEAL"file name" RESET">, <" LIME"s1" RESET">, <" LIME"s2" RESET">." << std::endl;
		return (0);
	}
	inFile.open(argv[1]);
	if (!inFile.is_open())
	{
		std::cerr << Rainbow("Error!\n\tThe file can't be opened.") << std::endl;
		return (0);
	}
	process_lines(inFile, argv[1], argv[2], argv[3]);
	inFile.close();
}