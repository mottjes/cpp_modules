#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main(void)
{
    {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");

        Bureaucrat otto("otto", 1);

        otto.signForm(*rrf);
        otto.executeForm(*rrf);
        delete rrf;
    }
}
