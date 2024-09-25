#include "../include/Bureaucrat.hpp"

int main(void)
{
    try
    {
        Form a("A38", 165, 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form b("Test", 10, 10);
        std::cout << std::endl << b << std::endl << std::endl;

        Bureaucrat bob("Bob", 5);
        Bureaucrat otto("Otto", 145);

        bob.signForm(b);
        otto.signForm(b);

        std::cout << std::endl << b << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
