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

    void    _parseData(std::string line);
    void    _validateInput(std::string line);
    void    _calculate(float value, std::string date);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &rhs);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange &rhs);

    void    handleInput(std::string input);

};
