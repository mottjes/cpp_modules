#include "../include/Character.hpp"

Character::Character() : _name("default")
{
    std::cout << "Character Default Constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
		_slots[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
    std::cout << "Character Constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
		_slots[i] = NULL;
}

Character::Character(const Character &rhs)
{
    std::cout << "Character copy Constructor called" << std::endl;
    *this = rhs;
}

Character& Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
        	if (_slots[i])
				delete _slots[i];
			if (rhs._slots[i])
				_slots[i] = rhs._slots[i]->clone();
			else
				_slots[i] = NULL;
    	}
	}
	return *this;
}

Character::~Character()
{
    std::cout << "Character Destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i])
        	delete _slots[i];
    }
}

std::string const & Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if(_slots[i] == NULL)
		{
			_slots[i] = m;
			return ;
		}
	}
}
void Character::unequip(int idx)
{
	_slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx > 3 && idx >= 0)
        return ;
	else if (_slots[idx] != NULL)
		_slots[idx]->use(target);
}
		
