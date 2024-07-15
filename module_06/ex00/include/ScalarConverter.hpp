#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <ctype.h>

class	ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &rhs);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter &rhs);

public:
	
	static void	convert(std::string literal);

};