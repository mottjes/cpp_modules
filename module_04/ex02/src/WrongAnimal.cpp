#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("unknown")
{
    std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
    *this = rhs;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << this->getType() << ": ***WrongAnimal Sound***" << std::endl;
}

std::string WrongAnimal::getType(void)const
{
    return _type;
}
