#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void)
{
    {
        ShrubberyCreationForm Form("home");
        Bureaucrat            fred("fred", 1);

        fred.executeForm(Form);
        fred.signForm(Form);
        fred.executeForm(Form);
    }
    std::cout << "-----------------------------------------" << std::endl;
    {
        RobotomyRequestForm Form("C3PO");
        Bureaucrat          dylan("dylan", 73);
        Bureaucrat          bob("bob", 5);

        dylan.executeForm(Form);
        dylan.signForm(Form);
        dylan.executeForm(Form);
        bob.signForm(Form);
        bob.executeForm(Form);
    }
    std::cout << "-----------------------------------------" << std::endl;
    {
        PresidentialPardonForm Form("Peter");
        Bureaucrat          alice("alice", 6);
        Bureaucrat          max("max", 5);

        alice.executeForm(Form);
        alice.signForm(Form);
        alice.executeForm(Form);
        max.executeForm(Form);
    }
}
