#include "../include/Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default Constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = "[null]";
}

Brain::Brain(const Brain &rhs)
{
    std::cout << "Brain Copy Constructor called" << std::endl;
    *this = rhs;
}

Brain& Brain::operator=(const Brain &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = rhs._ideas[i];
    }
	return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

std::string Brain::getIdea(int i)const
{
    return _ideas[i];
}

void Brain::setIdea(int i, std::string string)
{
    _ideas[i] = string;
}
