#include "ClapTrap.hpp"

//	Default constructor
ClapTrap::ClapTrap() : _name("null"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

//	Parameterized constructor
ClapTrap::ClapTrap(std::string name) :  _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Parameterized Constructor called" << std::endl;
}

//	Copy constuctor
ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = rhs;
}

//	Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

//	Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " Points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " don't has energy points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap is already defeated!" << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " repairs itself and gets " << amount << " hit points and has now " << this->_hitPoints << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " don't has energy points left!" << std::endl;
}
