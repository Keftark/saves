#include "RPN.hpp"

RPN &RPN::operator=(const RPN &a)
{
	if (this != &a)
		this->myStack = a.myStack;
	return (*this);
}

bool RPN::isOperator(std::string &str)
{
	if (str.length() != 1)
		return false;
	if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
		return true;
	return false;
}

bool RPN::isNumber(const std::string &str)
{
    if (str.empty())
        return false;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
        if (!isdigit(*it) && !(it == str.begin() && *it == '-'))
            return false;
    }
    return true;
}

void RPN::doOperation(std::string s1, std::string s2, std::string op)
{
	std::string result;
	std::stringstream ss;
	float fValue;
	switch (op[0])
	{
		case '+':
			fValue = atof(s2.c_str()) + atof(s1.c_str());
		break;
		case '-':
			fValue = atof(s2.c_str()) - atof(s1.c_str());
		break;
		case '*':
			fValue = atof(s2.c_str()) * atof(s1.c_str());
		break;
		case '/':
			fValue = atof(s2.c_str()) / atof(s1.c_str());
		break;
	}
	ss << fValue;
	myStack.push(ss.str());
}

void RPN::exitError()
{
	std::cout << ERRCOLOR << "Error" << RESET << std::endl;
	exit(EXIT_FAILURE);
}

void RPN::checkStackSize()
{
	if (myStack.size() == 0)
		exitError();
}

void RPN::CheckNumbers(std::string str)
{
	std::istringstream iss(str);
    std::string token;
    while (iss >> token)
	{
		if (token.length() > 1)
			exitError();
	}	
}

void RPN::run(std::string str)
{
	CheckNumbers(str);
	std::istringstream iss(str);
    std::string token;
	int i = 0;
    while (iss >> token)
	{
		if (isOperator(token))
		{
			checkStackSize();
			std::string s1 = myStack.top();
			myStack.pop();
			checkStackSize();
			std::string s2 = myStack.top();
			myStack.pop();
			doOperation(s1, s2, token);
		}
		else if (isNumber(token))
		{
			i++;
        	myStack.push(token);
		}
		else
			exitError();
	}
	if (myStack.size() == 1)
	{
		while (!myStack.empty())
		{
			std::cout << myStack.top() << std::endl;
			myStack.pop();
		}
	}
	else
		exitError();
}