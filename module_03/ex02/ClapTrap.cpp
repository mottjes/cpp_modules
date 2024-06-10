#include "ClapTrap.hpp"

//	Default constructor
ClapTrap::ClapTrap() : _name("null"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

//	Parameterized constructor
ClapTrap::ClapTrap(std::string name) :  _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Clap Trap Parameterized Constructor called" << std::endl;
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
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return *this;
}

//	Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "Clap Trap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " Points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << _name << " don't has energy points or hit points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap is already defeated!" << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " repairs itself and gets " << amount << " hit points and has now " << _hitPoints << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " don't has energy points or hit points left!" << std::endl;
}
