#include "ScavTrap.hpp"

// Default Constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardMode = false;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardMode = false;
	std::cout << "ScavTrap Parameterized Constructor called" << std::endl;
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

//	Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap &rhs)
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

// Destructor
ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap Destroctor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " Points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ScavTrap " << _name << " don't has energy points or hit points left!" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (_energyPoints > 0 && _hitPoints > 0 && _guardMode == false)
	{
		std::cout <<  _name << " is now in Gate keeper mode!" << std::endl;
		_guardMode = true;
	}
	else if (_guardMode == true)
		std::cout << _name << " is already in Gate keeper mode!" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " don't has energy or hit points left!" << std::endl;
}
