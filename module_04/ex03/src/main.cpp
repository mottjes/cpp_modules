#include "../include/MateriaSource.hpp"
#include "../include/Character.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

int main()
{
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;
	// return 0;

    IMateriaSource *src = new MateriaSource();
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    AMateria *tmp;

    me->use(0, *bob);
    tmp = src->createMateria("test");
    me->equip(tmp);
    AMateria *ice = new Ice();
    src->learnMateria(ice);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);

    std::cout << "----------------" << std::endl;
    me->use(0, *bob);
    std::cout << "----------------" << std::endl;
    
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(5, *bob);
    me->unequip(0);
    me->use(0, *bob);

    delete tmp;
    delete src;
    delete me;
    delete bob;
}
