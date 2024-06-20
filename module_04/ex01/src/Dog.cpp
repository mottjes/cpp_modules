#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog Default Constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog &rhs) : Animal(rhs)
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    _brain = new Brain(*rhs._brain);
}

Dog& Dog::operator=(const Dog &rhs)
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

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    delete _brain;
}

void Dog::makeSound()const
{
    std::cout << this->getType() << ": ***WOOOOOF***" << std::endl;
}

std::string Dog::getType(void)const
{
    return _type;
}

Brain* Dog::getBrain(void)const
{
    return _brain;
}
