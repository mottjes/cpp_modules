#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *_brain;    

public:
    Dog();
    Dog(const Dog &rhs);
    Dog& operator=(const Dog &rhs);
    ~Dog();

    void makeSound(void)const;
    std::string getType(void)const;
    Brain* getBrain(void)const;
    
};

#endif
