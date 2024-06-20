#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string     _name;
    AMateria*   _slots[4];

public:
    Character();
    Character(std::string name);
    Character(const Character &rhs);
    Character& operator=(const Character &rhs);
    ~Character();

    std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

};
