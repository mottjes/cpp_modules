#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *_brain;

public:
    Cat();
    Cat(const Cat &rhs);
    Cat& operator=(const Cat &rhs);
    ~Cat();

    void makeSound(void)const;
    std::string getType(void)const;
    Brain* getBrain(void)const;

};

#endif
