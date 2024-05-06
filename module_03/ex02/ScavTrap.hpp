#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool	_guardMode;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &rhs);
	ScavTrap& operator=(const ScavTrap &rhs);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate();
};

#endif
