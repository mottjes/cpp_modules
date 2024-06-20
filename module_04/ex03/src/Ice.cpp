#include "../include/Ice.hpp"

Ice::Ice() : AMateria()
{
    std::cout << "Ice default Constructor called" << std::endl;
	_type = "ice";
}

Ice::Ice(const Ice &rhs) : AMateria(rhs)
{
    std::cout << "Ice Copy Constructor called" << std::endl;
	*this = rhs;
}

Ice& Ice::operator=(const Ice &rhs)
{
    (void)rhs;
	return *this;
}

Ice::~Ice()
{
    std::cout << "Ice Destructor called" << std::endl;
}

Ice* Ice::clone() const
{
	Ice *i = new Ice();
	return i;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
