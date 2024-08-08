#include "../include/Span.hpp"

Span::Span() : _n(0)
{
}

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &rhs)
{
	*this = rhs;
}

Span& Span::operator=(const Span &rhs)
{
	if (this != &rhs)
		_n = rhs._n;
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber(int number)
{
	if (_numbers.size() + 1 > _n)
		throw std::logic_error("The Span is full!");
	else
		_numbers.push_back(number);
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if ((_numbers.size() + std::distance(begin, end)) > _n)
		throw std::logic_error("The Span is full!");
	else
		_numbers.insert(_numbers.end(), begin, end);
}

int	Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::logic_error("Needs two or more numbers to calculate shortest Span!");
	else
	{
		std::vector<int> copy(_numbers);

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
	if (_numbers.size() < 2)
		throw std::logic_error("Needs two or more numbers to calculate longest Span!");
	else
	{
		int min, max;
		
		min = *std::min_element(_numbers.begin(), _numbers.end());
		max = *std::max_element(_numbers.begin(), _numbers.end());
		return (max - min);
	}
}
