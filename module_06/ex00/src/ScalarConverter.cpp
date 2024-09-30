#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
	(void)rhs;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}

static bool isChar(const std::string literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]))
		return true;
	return false;
}

static bool isInt(const std::string literal)
{
	size_t i = 0;

	if (literal[0] == '-' || literal[0] == '+')
		i++;
	for (; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}

static bool isFloat(const std::string literal)
{
	size_t	i = 0;
	bool	has_point;

	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;
	if (literal[literal.length() - 1] != 'f')
		return false;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	if (literal[i] == '.')
		return false;
	for (; i < literal.length() - 1; i++)
	{
		if (!std::isdigit(literal[i]) && literal[i] != '.')
			return false;
		if (literal[i] == '.' && has_point == true)
			return false;
		if (literal[i] == '.')
			has_point = true;
	}
	return true;
}

static bool isDouble(const std::string literal)
{
	size_t	i = 0;
	bool	has_point;

	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	if (literal[i] == '.')
		return false;
	for (; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]) && literal[i] != '.')
			return false;
		if (literal[i] == '.' && has_point == true)
			return false;
		if (literal[i] == '.')
			has_point = true;
	}
	return true;
}

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE,
};

static e_type	getType(const std::string literal)
{
	if (isChar(literal))
		return CHAR;
	if (isInt(literal))
		return INT;
	if (isFloat(literal))
		return FLOAT;
	if (isDouble(literal))
		return DOUBLE;
	return NONE;
}

static void	convertChar(char c)
{
	std::cout << "  Char: '" << c << "'" << std::endl;
	std::cout << "   Int: " << static_cast<int>(c) << std::endl;
	std::cout << " Float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "Double: " << static_cast<double>(c) << ".0" << std::endl;
}

static bool intOverflow(std::string literal)
{
	long nb;

	nb = std::atol(literal.c_str());
	if (literal[0] == '-')
	{
		if (literal.length() > 11 || nb < std::numeric_limits<int>::min())
			return true;
	}
	else if (literal[0] == '+')
	{
		if (literal.length() > 11 || nb > std::numeric_limits<int>::max())
			return true;
	}
	else
	{
		if (literal.length() > 10 || nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
			return true;
	}
	return false;
}

static void	convertInt(std::string literal)
{
	int nb;

	if (intOverflow(literal))
	{
		std::cout << "  Char: impossible" << std::endl;
		std::cout << "   Int: impossible" << std::endl;
		std::cout << " Float: impossible" << std::endl;
		std::cout << "Double: impossible" << std::endl;
	}	
	else
	{
		nb = std::atoi(literal.c_str());
		
		if (isascii(nb) && std::isprint(nb))
			std::cout << "  Char: '" << static_cast<char>(nb) << "'" << std::endl;
		else
			std::cout << "  Char: Non displayable" << std::endl;
		std::cout << "   Int: " << nb << std::endl;
		std::cout << " Float: " << static_cast<float>(nb) << ".0f" << std::endl;
		std::cout << "Double: " << static_cast<double>(nb) << ".0" << std::endl;
	}
}

static void	convertFloat(std::string literal)
{
	float nb = std::atof(literal.c_str());

	if (nb > static_cast<float>(std::numeric_limits<int>::max())
		|| nb < static_cast<float>(std::numeric_limits<int>::min())
		|| literal == "+inff" || literal == "-inff" || literal == "nanf")
	{
		std::cout << "  Char: impossible" << std::endl;
		std::cout << "   Int: impossible" << std::endl;
		std::cout << " Float: " << nb << "f" << std::endl;
		std::cout << "Double: " << static_cast<double>(nb) << std::endl;
	}
	else
	{
		if (isascii(nb) && std::isprint(nb))
			std::cout << "  Char: '" << static_cast<char>(nb) << "'" << std::endl;
		else
			std::cout << "  Char: Non displayable" << std::endl;
		std::cout << "   Int: " << static_cast<int>(nb) << std::endl;
		std::cout << " Float: " << nb <<  ".0f" << std::endl;
		std::cout << "Double: " << static_cast<double>(nb) << ".0" << std::endl;
	}
}

static void	convertDouble(std::string literal)
{
	double nb = std::atof(literal.c_str());

	if (nb > static_cast<double>(std::numeric_limits<int>::max())
		|| nb < static_cast<double>(std::numeric_limits<int>::min())
		|| literal == "+inf" || literal == "-inf" || literal == "nan")
	{
		std::cout << "  Char: impossible" << std::endl;
		std::cout << "   Int: impossible" << std::endl;
		std::cout << " Float: " << nb << "f" << std::endl;
		std::cout << "Double: " << static_cast<double>(nb) << std::endl;
	}
	else
	{
		if (isascii(nb) && std::isprint(nb))
			std::cout << "  Char: '" << static_cast<char>(nb) << "'" << std::endl;
		else
			std::cout << "  Char: Non displayable" << std::endl;
		std::cout << "   Int: " << static_cast<int>(nb) << std::endl;
		std::cout << " Float: " << nb <<  ".0f" << std::endl;
		std::cout << "Double: " << static_cast<double>(nb) << ".0" << std::endl;
	}
}

void	ScalarConverter::convert(const std::string literal)
{
	switch(getType(literal))
	{
		case CHAR:
			convertChar(literal[0]);
			break ;
		case INT:
			convertInt(literal);
			break ;
		case FLOAT:
			convertFloat(literal);
			break ;
		case DOUBLE:
			convertDouble(literal);
			break ;
		default:
			std::cout << "  Char: impossible" << std::endl;
			std::cout << "   Int: impossible" << std::endl;
			std::cout << " Float: impossible" << std::endl;
			std::cout << "Double: impossible" << std::endl;
			break;
	}
}
