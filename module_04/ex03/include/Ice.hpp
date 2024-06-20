#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
private:

public:
	Ice();
	Ice(const Ice &rhs);
	Ice& operator=(const Ice &rhs);
	~Ice();

	Ice* clone() const;
	void use(ICharacter& target);
};
