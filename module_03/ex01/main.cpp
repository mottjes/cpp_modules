#include "ScavTrap.hpp"

int	main(void)
{
	/*
	ClapTrap a("Bob");
	ClapTrap b;


	a.attack("Peter");
	b.takeDamage(8);
	b.beRepaired(2);
	a.beRepaired(2);
	a.attack("Daniel");
	for (int i = 0; i < 8; i++)
		a.beRepaired(1);
	*/
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