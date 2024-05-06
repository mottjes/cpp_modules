#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;

    std::cout << "-------------------" << std::endl;

    Animal *animals[10];

    for(int i = 0; i < 10; i++)
    {
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
        
    for (int i = 0; i < 10; i++)
        delete animals[i];
    
    std::cout << "-------------------" << std::endl;

    Cat *cat = new Cat();
    Cat *cat2 = new Cat();

    *cat2 = *cat;
    std::cout << "cat  idea : " << cat->getBrain()->getIdea(0) << std::endl;
    std::cout << "cat2 idea : " << cat2->getBrain()->getIdea(0) << std::endl;

    cat->getBrain()->setIdea(0, "I am hungry");
    std::cout << "cat  idea : " << cat->getBrain()->getIdea(0) << std::endl;
    std::cout << "cat2 idea : " << cat2->getBrain()->getIdea(0) << std::endl;

    *cat2 = *cat;
    std::cout << "cat  idea : " << cat->getBrain()->getIdea(0) << std::endl;
    std::cout << "cat2 idea : " << cat2->getBrain()->getIdea(0) << std::endl;

    delete cat;
    delete cat2;

    return 0;
}