#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::map<std::string, float> _btcData;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &rhs);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange &rhs);

    void    parseData(std::string line);
    void    handleInput(std::string input);
    void    validateInput(std::string line);
    bool    validateDate(std::string token, int *year, int *month, int *day);
    bool    validateValue(std::string token, float *value);
    bool    isLeapYear(int year);
    void    calculate(float value, std::string date);
    void    print(std::string date, float value, float exchangeRate);

   
};
