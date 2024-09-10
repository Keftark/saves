#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		Error_Msg("The program must take one argument to run properly.");
		return 1;
	}
	RPN rpn;
	rpn.run(argv[1]);
}
