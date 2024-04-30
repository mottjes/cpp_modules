#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("Peter");

	
	a.attack("Dylan");
	a.guardGate();
	a.takeDamage(25);
	a.beRepaired(20);
}
