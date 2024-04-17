#include "HumanB.hpp"

HumanB::HumanB(std::string name) :_name(name), _weapon(NULL)
{
	std::cout << "Created HumanB: " <<this->_name << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "Destroyed HumanB: " <<this->_name << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	std::cout << this->_name << "s weapon set to " << weapon.getType() << std::endl;
}
