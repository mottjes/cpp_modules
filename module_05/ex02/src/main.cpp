#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void)
{
    ShrubberyCreationForm a("home");
    Bureaucrat            fred("fred", 1);

    fred.executeForm(a);
    fred.signForm(a);
    fred.executeForm(a);
}
