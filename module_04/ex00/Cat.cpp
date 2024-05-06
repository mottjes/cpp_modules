#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat Default Constructor called" << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat &rhs) : Animal(rhs)
{
    std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
		_type = rhs._type;
	return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << this->getType() << ": ***Meoooow***" << std::endl;
}

std::string Cat::getType(void)const
{
    return _type;
}