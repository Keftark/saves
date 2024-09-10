#ifndef SPAN_HPP
# define SPAN_HPP

# include "Colors.hpp"
# include <list>
# include <iostream>
# include <climits>
# include <cmath>
# include <algorithm>
# include <cstdlib>
# include <ctime>

class Span
{
	private:
		std::list<int> myList;
		unsigned int nbr;
    	Span &operator=(const Span &a);
		int errorMessage(bool isShortest);
		Span();
	public:
		~Span();
		Span(const Span &a);
		Span(unsigned int n);
		void addNumber(int n);
		void addNumbers(int listSize);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		std::list<int> getList();
};

#endif