#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:
    WrongCat();
    WrongCat(const WrongCat &rhs);
    WrongCat& operator=(const WrongCat &rhs);
    ~WrongCat();

    void makeSound(void)const;
    std::string getType(void)const;
};

#endif
