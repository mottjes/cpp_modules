#include "../include/Cure.hpp"

Cure::Cure() : AMateria()
{
    std::cout << "Cure default Constructor called" << std::endl;
	_type = "cure";
}

Cure::Cure(const Cure &rhs) : AMateria(rhs)
{
    std::cout << "Cure Copy Constructor called" << std::endl;
	*this = rhs;
}

Cure& Cure::operator=(const Cure &rhs)
{
    (void)rhs;
	return *this;
}

Cure::~Cure()
{
    std::cout << "Cure Deconstructor called" << std::endl;
}

Cure* Cure::clone() const
{
	Cure *c = new Cure();
	return c;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
