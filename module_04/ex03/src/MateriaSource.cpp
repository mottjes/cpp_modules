#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
		_slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &rhs)
{
    *this = rhs;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &rhs)
{
    if (this != &rhs)
	{
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

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i])
        	delete _slots[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i] == NULL)
        {
            _slots[i] = m;
            return ;
        }  
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 3; i >= 0; i--)
    {
        if (_slots[i] && _slots[i]->getType() == type)
            return _slots[i]->clone();
    }
    return 0;
}
