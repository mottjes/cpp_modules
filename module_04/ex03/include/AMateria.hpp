#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string	_type;

public:
	AMateria();
	AMateria(const AMateria &rhs);
	AMateria& operator=(const AMateria &rhs);
	virtual ~AMateria();

	AMateria(std::string const & type);

	std::string const  & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

};
