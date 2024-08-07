#include "../include/Span.hpp"

Span::Span() : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span &rhs)
{
	*this = rhs;
}

Span& Span::operator=(const Span &rhs)
{
	if (this != &rhs)
		_N = rhs._N;
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber(int number)
{
	if (_Numbers.size() + 1 > _N)
		throw std::logic_error("The Span is full!");
	else
		_Numbers.push_back(number);
}

int	Span::shortestSpan()
{
	if (_Numbers.size() < 2)
		throw std::logic_error("Needs two or more numbers to calculate shortest Span!");
	else
	{
		std::vector<int> copy(_Numbers);

		std::sort(copy.begin(), copy.end());

		int shortestSpan = std::abs(copy[1] - copy[0]);
		for (size_t i = 2; i <= copy.size(); i++)
		{
			if (std::abs(copy[i] - copy[i - 1]) < shortestSpan)
				shortestSpan = std::abs(copy[i] - copy[i - 1]);
		}
		return (shortestSpan);
	}
}

int Span::longestSpan()
{
	if (_Numbers.size() < 2)
		throw std::logic_error("Needs two or more numbers to calculate longest Span!");
	else
	{
		int min, max;
		
		min = *std::min_element(_Numbers.begin(), _Numbers.end());
		max = *std::max_element(_Numbers.begin(), _Numbers.end());
		return (max - min);
	}
}
