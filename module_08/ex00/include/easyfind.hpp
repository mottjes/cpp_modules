#pragma once

#include <iostream>
#include <algorithm>
#include <exception>

template<typename T>
typename T::iterator	easyfind(T &container, int find)
{
	typename T::iterator it;
	it  = std::find(container.begin(), container.end(), find);
	if (it == container.end())
		throw std::out_of_range("Value not found!");
	else
		return (it);
}
