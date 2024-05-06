#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog Default Constructor called" << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog &rhs) : Animal(rhs)
{
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
		_type = rhs._type;
	return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound()const
{
    std::cout << this->getType() << ": ***WOOOOOF***" << std::endl;
}

std::string Dog::getType(void)const
{
    return _type;
}