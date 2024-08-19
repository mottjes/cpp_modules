#pragma once

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &rhs) : std::stack<T>(rhs) {}
	~MutantStack() {}
	MutantStack& operator=(const MutantStack &rhs)
    {
        if (this != &rhs)
            std::stack<T>::operator=(rhs);
    	return *this;
    }

    typedef typename std::deque<T>::iterator iterator;

    iterator begin()
    {
        return (this->c.begin());
    }

    iterator end()
    {
        return (this->c.end());
    }

};