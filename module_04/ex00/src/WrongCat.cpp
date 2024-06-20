#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat Default Constructor called" << std::endl;
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &rhs) : WrongAnimal(rhs)
{
    std::cout << "WrongCat Copy Constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &rhs)
{
    if (this != &rhs)
		_type = rhs._type;
	return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << this->getType() << ": ***Meoooow***" << std::endl;
}

std::string WrongCat::getType(void)const
{
    return _type;
}