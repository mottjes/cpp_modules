#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string _type;

public:
    Animal();
    Animal(const Animal &rhs);
    Animal& operator=(const Animal &rhs);
    virtual ~Animal();

    virtual void makeSound(void)const;
    std::string getType(void)const;

};

#endif
