#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t delim = line.find(',');

        std::string date = trim(line.substr(0, delim));
        std::string value = trim(line.substr(delim + 1, line.length()));
        data[date] = value;
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &a)
{
    *this = a;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &a)
{
    if (this != &a)
        data = a.data;
    return *this;
}

bool isFileEmpty(const std::string& filename)
{
    std::ifstream file(filename.c_str(), std::ios::ate);
    return file.tellg() == 0;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::run(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open())
	{
        std::cout << ERRCOLOR << "Error: file does not exist" << RESET << std::endl;
        exit(EXIT_FAILURE);
    }
    if (isFileEmpty(filename.c_str()))
	{
        std::cout << ERRCOLOR << "Error: file is empty" << RESET << std::endl;
        exit(EXIT_FAILURE);
    }
    std::getline(file, line);
    if (line != "date | value")
	{
        std::cout << ERRCOLOR << "Error: invalid file format" << RESET << std::endl;
        exit(EXIT_FAILURE);
    }
    while (std::getline(file, line))
    {
        size_t delim = line.find('|');
        if (delim == std::string::npos)
        {
            std::cout << ERRCOLOR << "Error: bad input => " << line << RESET << std::endl;
            continue;
        }
        std::string date = trim(line.substr(0, delim));
        std::string value = trim(line.substr(delim + 1));
        try
		{
            if (!validDate(date))
                throw std::invalid_argument("invalid date: " + (date.empty() ? "\"\"" : "'" + date + "'"));
            if(value.empty())
                throw std::invalid_argument("invalid value: " + (value.empty() ? "\"\"" : "'" + value + "'"));
            validateNumber(value);
            std::map<std::string, std::string>::iterator it;
            std::string prevDate = date;
            it = data.find(date);
            while (it == data.end())
            {
                const std::string &currentDate = prevDate;
                prevDate = previousDate(currentDate);
                it = data.find(prevDate);
            }
            std::cout << TEAL << date << RESET << " = " << GOLD <<
            stod(it->second) * stod(value) << RESET <<
            " (" << TEAL << it->second << " * " << value << RESET << ")" << std::endl;
        }
		catch (std::exception &e)
		{
            std::cout << ERRCOLOR << "Error: " << e.what() << RESET << std::endl;
        }
    }
    file.close();
}

bool BitcoinExchange::isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int BitcoinExchange::stoi(const std::string &str)
{
    std::stringstream ss(str);
    int value;
    ss >> value;
    return value;
}

double BitcoinExchange::stod(const std::string &str)
{
    std::stringstream ss(str);
    double value;
    ss >> value;
    return value;
}

std::string BitcoinExchange::toString(int value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

std::string BitcoinExchange::previousDate(const std::string &date)
{
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
        daysInMonth[2] = 29;
    day--;
    if (day == 0)
	{
        month--;
        if (month == 0)
		{
            month = 12;
            year--;
        }
        day = daysInMonth[month];
    }
    std::string newYear = toString(year);
    std::string newMonth = (month < 10) ? "0" + toString(month) : toString(month);
    std::string newDay = (day < 10) ? "0" + toString(day) : toString(day);
    return newYear + "-" + newMonth + "-" + newDay;
}

std::string BitcoinExchange::trim(const std::string &str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return str;
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::fileExists(const std::string &filename)
{
    std::fstream file(filename.c_str());
    bool exists = file.good();
    file.close();
    return exists;
}

bool BitcoinExchange::fileIsEmpty(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    bool isEmpty = file.peek() == std::ifstream::traits_type::eof();
    file.close();
    return isEmpty;
}

void BitcoinExchange::validateNumber(const std::string &str)
{
    double value;
    try
	{
        if (std::find(str.begin(), str.end(), '.') != str.end())
		{
            size_t decimalPoint = str.find('.');
            if (std::find(str.begin() + decimalPoint + 1, str.end(), '.') != str.end())
                throw std::invalid_argument("too many decimal points");
        }
        bool hasSign = str[0] == '+' || str[0] == '-';
        for (size_t i = hasSign ? 1 : 0; i < str.length(); i++)
        {
            if (::isdigit(str[i]) || str[i] == '.')
                continue;
            throw std::invalid_argument("not a number => " + str);
        }

        value = stod(str);

    }
    catch (std::exception &e)
    {
        throw std::invalid_argument("not a number => " + str);
    }
    if (value > 1000.0)
        throw std::invalid_argument("number must be below 1000");
    else if (value < 0)
        throw std::invalid_argument("not a positive number");
}


bool BitcoinExchange::allDigit(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!::isdigit(str[i]))
            return false;
    }
    return true;
}

bool BitcoinExchange::validDate(const std::string &date)
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    if (!allDigit(year) || !allDigit(month) || !allDigit(day))
        return false;
    int yearInt, monthInt, dayInt;
    std::stringstream ssYear(year);
    std::stringstream ssMonth(month);
    std::stringstream ssDay(day);
    ssYear >> yearInt;
    ssMonth >> monthInt;
    ssDay >> dayInt;
    if ((yearInt < 2009 || yearInt > 2022) ||
        (monthInt < 1 || monthInt > 12) ||
        (dayInt < 1 || dayInt > 31))
        return false;
    if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
        return false;
    if (monthInt == 2)
    {
        bool isLeap = isLeapYear(yearInt);
        if (dayInt > (isLeap ? 29 : 28))
            return false;
    }
    return true;
}