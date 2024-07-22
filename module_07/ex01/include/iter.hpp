#pragma once

#include <iostream>

template<typename T>
void	iter(T *array, size_t array_len, void (*func)(T&))
{
	for (size_t i = 0; i < array_len; i++)
		func(array[i]);
}

template<typename T>
void printElement(T element)
{
	std::cout << element << " ";
}

template<typename T>
void plusFive(T& element)
{
	element += 5;
}
