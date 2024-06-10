#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Form a("A38", 165, 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Form b("Test", 10, 10);

    std::cout << std::endl << b << std::endl << std::endl;

    Bureaucrat c("Bob", 5);
    Bureaucrat d("Otto", 145);

    d.signForm(b);
    c.signForm(b);

    std::cout << std::endl << b << std::endl << std::endl;
}
