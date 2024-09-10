#include "PMergeMe.hpp"

// make re && ./PMergeMe `shuf -i 1-100000 -n 8000 | tr "\n" " "`
int main(int argc, char *argv[])
{
	PMergeMe pMergeMe;
	if (argc < 3)
	{
		std::cout << ERRCOLOR << "Error: The program takes at least 2 parameters to run." << RESET << std::endl;
		return 1;
	}
	if (pMergeMe.CheckNumbers(argc, argv))
		return 1;
	pMergeMe.SaveNumbers(argc, argv);
	std::cout << TEAL << "Before:\t" << CORAL;
	pMergeMe.ShowNumbers();
	pMergeMe.DoSort();
	std::cout << TEAL << "After:\t" << CORAL;
	pMergeMe.ShowNumbers();
	pMergeMe.ShowTimers();
}
