#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie " << this->_name << " created!" << std::endl; 
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->_name << " deleted!" << std::endl; 
}

void Zombie::announce(void)
{
	std::cout << this->_name	<< ": BraiiiiiiinnnzzzZ..." << std::endl;
}
