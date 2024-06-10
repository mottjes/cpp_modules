#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int	main(void)
{
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
