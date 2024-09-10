#ifndef RPN_HPP
# define RPN_HPP

# include "Colors.hpp"
# include <stack>
# include <cstdlib>

class RPN
{
	private:
		std::stack<std::string> myStack;
		void doOperation(std::string s1, std::string s2, std::string op);
		bool isOperator(std::string &str);
		bool isNumber(const std::string &str);
		void checkStackSize();
		void exitError();
		void CheckNumbers(std::string str);
	public:
		RPN() {}
		~RPN() {}
		RPN(const RPN &a) {*this = a;}
		RPN &operator=(const RPN &a);
		void run(std::string str);
};

#endif