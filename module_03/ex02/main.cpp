#include "ScavTrap.hpp"
#include "FragTrap.hpp"


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
	*/
	FragTrap e;
	FragTrap f("Alice");

	e.highFivesGuys();
	e.attack("Tom");
	e.takeDamage(101);
	e.takeDamage(1);
	e.attack("some random dude");
	e.highFivesGuys();
	f.takeDamage(20);
	f.beRepaired(10);
	f.highFivesGuys();
}
