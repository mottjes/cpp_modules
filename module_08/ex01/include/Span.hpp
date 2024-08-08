#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
private:
	unsigned int		_n;
	std::vector<int>	_numbers;

	Span();

public:
	Span(unsigned int N);
	Span(const Span &rhs);
	Span& operator=(const Span &rhs);
	~Span();

	void	addNumber(int number);
	void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int 	shortestSpan();
	int		longestSpan();
};