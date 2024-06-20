#include "../include/Cure.hpp"

Cure::Cure() : AMateria()
{
	_type = "cure";
}

Cure::Cure(const Cure &rhs) : AMateria(rhs)
{
	*this = rhs;
}

Cure& Cure::operator=(const Cure &rhs)
{
    (void)rhs;
	return *this;
}

Cure::~Cure()
{
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
