/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:00:28 by cpothin           #+#    #+#             */
/*   Updated: 2024/02/16 15:30:49 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Base.hpp"

Base *generate()
{
    int randomClass = (std::rand() % 3) + 1;
    switch (randomClass)
	{
        case 1:
            return new A();
        case 2:
            return new B();
        case 3:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << RGB(Colors::Magenta) << "* The identified type is A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << RGB(Colors::DarkMagenta) << "* The identified type is B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << RGB(Colors::DeepPink) << "* The identified type is C" << RESET << std::endl;
	else
		std::cout << RGB2(Colors::Red, Colors::Black) << "Problem!" << RESET << std::endl;
}

void identify(Base &p)
{
	Base a;
	
	try
	{
		a = dynamic_cast<A&>(p);
		std::cout << RGB(Colors::Magenta) << "& The identified type is A" << RESET << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	try
	{
		a = dynamic_cast<B&>(p);
		std::cout << RGB(Colors::DarkMagenta) << "& The identified type is B" << RESET << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	try
	{
		a = dynamic_cast<C&>(p);
		std::cout << RGB(Colors::DeepPink) << "& The identified type is C" << RESET << std::endl;
		return ;
	}
	catch (std::exception &e)
	{}}}
}

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	Base *base = generate();
	identify(base);
	identify(*base);

	std::cout << std::endl;
	
	delete (base);
	base = generate();
	identify(base);
	delete (base);
	base = generate();
	identify(base);
	delete (base);
	base = generate();
	identify(base);
	delete (base);
	base = generate();
	identify(base);
	delete (base);
	base = generate();
	identify(base);
	delete (base);
}
