#include "../include/Ice.hpp"

Ice::Ice() : AMateria()
{
	_type = "ice";
}

Ice::Ice(const Ice &rhs) : AMateria(rhs)
{
	*this = rhs;
}

Ice& Ice::operator=(const Ice &rhs)
{
    (void)rhs;
	return *this;
}

Ice::~Ice()
{
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
