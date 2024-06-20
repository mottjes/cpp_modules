#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

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

    const Animal* animal = i;
    animal->makeSound(); //will still output the cat sound!

    std::cout << "--------------------------" << std::endl;

    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_i = new WrongCat();

    std::cout << i->getType() << " " << std::endl;
    wrong_i->makeSound(); //will not output the cat sound!
    wrong_meta->makeSound();

    const WrongCat* Wrong_Cat = new WrongCat();
    Wrong_Cat->makeSound(); //will output the cat sound!

    delete Wrong_Cat;
    delete meta;
    delete j;
    delete i;
    delete wrong_meta;
    delete wrong_i;

    return 0;
}