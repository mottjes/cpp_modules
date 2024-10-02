#pragma once

#include <iostream>

template<typename T>
class Array
{
private:
	T*		_array;
	size_t	_size;

public:
	Array() : _array(NULL), _size(0)
	{
	}

	Array(unsigned int n) : _size(n)
	{
        if (_size)
		    _array = new T[_size];
        else
            _array = NULL;
	}
	Array(const Array &rhs) 
	{
        _array = NULL;
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
			    _array = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
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
