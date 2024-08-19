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
    void    parseInput(std::string line);
    void    validateDate(std::string token);
    void    validateValue(std::string token);
   
};
