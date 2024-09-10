#include "Span.hpp"

Span::Span(unsigned int n)
{
	nbr = n;
}

Span::~Span() {}

Span::Span() {}

Span::Span(const Span &a)
{
	*this = a;
}

Span &Span::operator=(const Span &a)
{
    if (this != &a)
        *this = a;
    return (*this);
}

void Span::addNumber(int n)
{
	if (this->myList.size() == this->nbr)
		throw std::out_of_range("Span::addNumber: max size reached!");
	else
	{
		this->nbr++;
		this->myList.push_back(n);
	}
}

void Span::addNumbers(int listSize)
{
	srand(time(NULL));

	for (int i = 0; i < listSize; i++)
		myList.push_back(rand() % 100); // do 'rand() % number' to create numbers below this value
}

int Span::errorMessage(bool isShortest)
{
	std::string str = isShortest ? "shortest" : "longest";
	if (myList.empty())
	{
		std::cout << ERRCOLOR << "The list is empty, I can't find the " << isShortest << " span." << RESET << std::endl;
		return (0);
	}
	else if (myList.size() == 1)
	{
		std::cout << ERRCOLOR << "The list has only one element, I can't find the " << isShortest << " span." << RESET << std::endl;
		return (0);
	}
	else
		return (1);
}

unsigned int Span::shortestSpan()
{
	if (errorMessage(true) == 0)
		return (0);
	unsigned int shortest = UINT_MAX;
	for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
	{
		std::list<int>::iterator it2 = it;
        ++it2;
        for (; it2 != myList.end(); ++it2)
		{
			unsigned int nbr = static_cast<unsigned int>(abs(*it - *it2));
			if (nbr < shortest)
				shortest = nbr;
		}
	}
	return (shortest);
}

unsigned int Span::longestSpan()
{
	if (errorMessage(false) == 0)
		return (0);
	int min = this->myList.front();
	int max = min;
	for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
	{
		if (*it < min)
			min = *it;
		if (*it > max)
			max = *it;
	}
	return (max - min);
}

std::list<int> Span::getList()
{
	return (this->myList);
}