#include "../include/Animal.hpp"

Animal::Animal() : _type("unknown")
{
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &rhs)
{
    std::cout << "Animal Copy Constructor called" << std::endl;
    *this = rhs;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

void Animal::makeSound() const
{
    std::cout << this->getType() << ": ***Animal Sound***" << std::endl;
}

std::string Animal::getType(void)const
{
    return _type;
}