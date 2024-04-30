#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("Bob");
	ClapTrap b;


	a.attack("Peter");
	b.takeDamage(8);
	b.beRepaired(2);
	a.beRepaired(2);
	a.attack("Daniel");
	for (int i = 0; i < 8; i++)
		a.beRepaired(1);
}
