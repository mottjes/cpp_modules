#pragma once

#include <iostream>

template<typename T>
class Array
{
private:
	T*		_array;
	size_t	_size;

public:
	Array() : _size(0)
	{
		_array = new T[_size];
	}

	Array(unsigned int n) : _size(n)
	{
		_array = new T[_size];
	}
	Array(const Array &rhs) 
	{
		*this = rhs;
	}

	~Array()
	{
		if (_array != NULL)
			delete [] _array;
	}

	Array& operator=(const Array &rhs)
	{
		if (this != &rhs)
		{
			if (_array != NULL)
				delete [] _array;
			_size = rhs.size();
			if (_size)
			{
				_array = new T[rhs.size()];
				for (size_t i = 0; i < rhs.size(); i++)
					_array[i] = rhs._array[i];
			}
		}
    	return *this;
	}

	T& operator[](size_t i) 
	{
        if (i >= _size)
            throw std::exception();
        return _array[i];
    }

	size_t size() const
	{
		return _size;
	} 

};
