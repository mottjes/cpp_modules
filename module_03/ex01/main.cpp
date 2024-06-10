#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap c;
	ScavTrap d("Peter");

	c.attack("Dylan");
	d.takeDamage(25);
	d.takeDamage(75);
	d.takeDamage(3);
	c.takeDamage(25);
	c.beRepaired(20);
	c.guardGate();
	c.guardGate();
}
