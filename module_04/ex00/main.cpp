#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();


    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_i = new WrongCat();

    std::cout << i->getType() << " " << std::endl;
    wrong_i->makeSound(); //will output the cat sound!
    wrong_meta->makeSound();


    delete meta;
    delete j;
    delete i;
    delete wrong_meta;
    delete wrong_i;

    return 0;
}