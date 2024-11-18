#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream   data("data.csv");
    std::string     line;

    if (!data)
		throw std::runtime_error("Error: could't open file data.csv");
    std::getline(data, line);
    while (std::getline(data, line))
        _parseData(line);
    data.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
    *this = rhs;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
	{
		_btcData.clear();
		std::map<std::string, float>::const_iterator it;
		for (it = rhs._btcData.begin(); it != rhs._btcData.end(); it++)
			_btcData[it->first] = it->second;
	}
	return *this;
}

static bool isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool validateDate(std::string token, int *year, int *month, int *day)
{
    if (token[4] != '-' || token[7] != '-' || token[10] != ' ' || token.size() != 11)
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            i++;
        if (!isdigit(token[i]))
            return false;
    }
    sscanf(token.c_str(), "%d-%d-%d ", year, month, day);
    if (*year < 1 || *month < 1 || *month > 12 || *day < 1)
        return false;
    
    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (*month == 2 && isLeapYear(*year)) {
        return (*day <= 29);
    }
    return (*day <= daysInMonth[*month]);
}

static bool validateValue(std::string token, float *value)
{
    bool    pointFound = false;
    bool    negative = false;

    if (token[0] != ' ')
        return false;
    for (size_t i = 1; i < token.size(); i++)
    {
        if (token[1] == '-' && !negative)
        {
            negative = true;
            i++;
        }
        if (!isdigit(token[i]) && token[i] != '.')
            return false;
        if (token[i] == '.')
        {
            if (pointFound)
                return false;
            pointFound = true;
        }
    }
    *value = atof(token.c_str());
    return true;
}

void BitcoinExchange::_parseData(std::string line)
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
    std::ifstream   infile(input.c_str());
    std::string     line;

    if (!infile)
	    throw std::runtime_error("Error: could not open file");
    getline(infile, line);
    if (line != "date | value")
        throw std::runtime_error("Error: invalid first line in input. Expected 'date | value'");
    while (getline(infile, line))
        _validateInput(line);
    infile.close();
}

void BitcoinExchange::_validateInput(std::string line)
{
    int                 year, month, day;
    float               value;
    std::stringstream   ss(line);
    std::string         token;
    std::string         date;
    int                 i = 0;
    bool                valid = false;

    if (line.size() < 14 || line[11] != '|')
    {
        std::cout << "Error: bad input" << " => " << line << std::endl;
        return ;
    }
    while (std::getline(ss, token, '|'))
    {
        if (i == 0)
        {
            date = token;
            valid = validateDate(token, &year, &month, &day);
        }
        if (i == 1 && valid)
            valid = validateValue(token, &value);
        if (i > 1 || valid == false)
        {
            std::cout << "Error: bad input" << " => " << line << std::endl;
            return ;
        }
        i++;
    }
    if (value > 1000)
        std::cout << "Error: too large number." << std::endl;
    else if (value < 0)
        std::cout << "Error: not a positive number." << std::endl;
    else
        _calculate(value, date);
}

void    BitcoinExchange::_calculate(float value, std::string date)
{
    std::map<std::string, float>::iterator  it;

    it = _btcData.lower_bound(date);
    if (it == _btcData.end() || it->first != date && it != _btcData.begin())
        it--;
    std::cout << date << " => " << value << " = "  << it->second * value << std::endl;
}
