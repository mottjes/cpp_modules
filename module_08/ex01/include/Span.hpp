#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
private:
	unsigned int		_N;
	std::vector<int>	_Numbers;

	Span();

public:
	Span(unsigned int N);
	Span(const Span &rhs);
	Span& operator=(const Span &rhs);
	~Span();

	void	addNumber(int number);
	int 	shortestSpan();
	int		longestSpan();
};