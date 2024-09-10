#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "Colors.hpp"
# include <iostream>
# include <climits>
# include <vector>
# include <list>
# include <ctime>
# include <iterator>
# include <iomanip>

struct Edge
{
    int source, destination, weight;
};

class PMergeMe
{
	private:
		double listTime, vectorTime;
		std::list<int> myList;
		std::vector<int> myVector;
		PMergeMe(const PMergeMe &a);
	public:
		PMergeMe() {}
		~PMergeMe() {}
		int CheckNumbers(int argc, char *argv[]);
		PMergeMe &operator=(const PMergeMe &a);
		void SaveNumbers(int argc, char *argv[]);
		void ShowNumbers();
		void DoSort();
		void ShowTimers();
};


#endif