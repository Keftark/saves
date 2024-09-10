#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include "Colors.hpp"
# include <map>
# include <fstream>
# include <string>
# include <utility>
# include <algorithm>

class BitcoinExchange
{
    std::map<std::string, std::string> data;
    std::string previousDate(const std::string &date);
    std::string nextDate(const std::string &date);
    std::string trim(const std::string &str);
    void validateNumber(const std::string &str);
    bool fileExists(const std::string &filename);
    bool fileIsEmpty(const std::string &filename);
    bool validDate(const std::string &date);
    bool isLeapYear(int year);
    bool allDigit(const std::string &str);
    int stoi(const std::string &str);
    double stod(const std::string &str);
    std::string toString(int value);
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &a);
    BitcoinExchange &operator=(const BitcoinExchange &a);
    ~BitcoinExchange();
    void run(const std::string &filename);
};

#endif