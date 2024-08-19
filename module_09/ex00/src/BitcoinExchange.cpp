#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream   data("data.csv");
    std::string     line;

    if (!data)
		throw std::runtime_error("Error: could't open file");
    std::getline(data, line);
    while (std::getline(data, line))
        parseData(line);
    data.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
    (void)rhs;
}

BitcoinExchange::~BitcoinExchange()
{
    
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    (void)rhs;
    return *this;
}

void BitcoinExchange::parseData(std::string line)
{
    std::stringstream   ss(line);
    std::string         date;
    std::string         value_str;
    float               value;

    getline(ss, date, ',');
    getline(ss, value_str, ',');

    value = static_cast<float>(atof(value_str.c_str()));
    _btcData.insert(std::make_pair(date, value));    
}

void BitcoinExchange::handleInput(std::string input)
{
    std::ifstream   infile(input);
    std::string     line;

    if (!infile)
	    throw std::runtime_error("Error: could't open file");
    getline(infile, line);
    //check date | value
    while (getline(infile, line))
        parseInput(line);
    infile.close();
}

void BitcoinExchange::parseInput(std::string line)
{
    std::stringstream   ss(line);
    std::string         token;
    int i = 0;

    while (getline(ss, token, '|'))
    {
        if (i > 1)
            //Error
        if (i == 0)
            validateDate(token);
        else
            validateValue(token);
    }


}

void BitcoinExchange::validateDate(std::string token)
{
    for (int i = 0; i < 12; i++)
    {
        if (i < 4)
            //check for digit
        if (i == 4)
        if (i)
    }


}

void BitcoinExchange::validateValue(std::string token)
{

}

