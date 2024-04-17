#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :_name(name),_weapon(weapon)
{
	std::cout << "Created HumanA: " <<this->_name << " with " << weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "Destroyed HumanA: " <<this->_name << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with " << _weapon.getType() << std::endl;
}
