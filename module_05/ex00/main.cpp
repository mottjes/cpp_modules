#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat  b1("Bob", 150);
    std::cout << b1 << std::endl;

    try
    {
        b1.incrementGrade();
        std::cout << b1 << std::endl;

        b1.decrementGrade();
        std::cout << b1 << std::endl;

        //  throws exception
        b1.decrementGrade();
        std::cout << b1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        //  throws exception
        Bureaucrat  b2("Anna", 0);
    }
     catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

