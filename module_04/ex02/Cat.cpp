#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat Default Constructor called" << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat &rhs) : Animal(rhs)
{
    std::cout << "Cat Copy Constructor called" << std::endl;
    _brain = new Brain(*rhs._brain);
}

Cat& Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
    {
        _type = rhs._type;
        if (_brain)
            delete _brain;
        _brain = new Brain(*rhs._brain);
    }
	return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    delete _brain;
}

void Cat::makeSound() const
{
    std::cout << this->getType() << ": ***Meoooow***" << std::endl;
}

std::string Cat::getType(void)const
{
    return _type;
}

Brain* Cat::getBrain(void)const
{
    return _brain;
}
