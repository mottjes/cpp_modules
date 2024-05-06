#include "FragTrap.hpp"

// Default Constructor
FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

// Parameterized constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "FragTrap Parameterized Constructor called" << std::endl;
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap &rhs) : ClapTrap(rhs)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

//	Copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap &rhs)
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
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destroctor called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (_energyPoints > 0 && _hitPoints > 0)
		std::cout << "FragTrap " << this->_name << ": Give me an Highfive broski!!!" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << ": I cant ask for Highfives anymore :(" << std::endl;
}
