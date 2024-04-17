#include "Zombie.hpp"

int	main(void)
{
	int size;
	
	size = 3;
	Zombie *zHorde = zombieHorde(size, "Frank");
	for (int i = 0; i < size; i++)
		zHorde[i].announce();
	delete[] zHorde;
}
