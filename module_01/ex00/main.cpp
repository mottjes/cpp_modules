#include "Zombie.hpp"

int	main(void)
{
	Zombie *z = newZombie("Frank");
	z->announce();
	randomChump("Max");
	delete z;
}
