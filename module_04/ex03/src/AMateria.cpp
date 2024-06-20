#include "../include/AMateria.hpp"

AMateria::AMateria() : _type("default")
{
    std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &rhs)
{
    std::cout << "AMateria Copy Constructor called" << std::endl;
    *this = rhs;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "AMateria Constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria Destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}