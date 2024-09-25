#include "../include/Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &rhs)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = rhs;
}

Intern&	Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm*    Intern::createShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm*    Intern::createRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm*    Intern::createPresidentalPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string formName,std::string target)
{
    std::string Forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*funcPtrArray[])(std::string) = {   &Intern::createShrubberyCreationForm, 
                                                        &Intern::createRobotomyRequestForm, 
                                                        &Intern::createPresidentalPardonForm };

    std::cout << "Intern creates " << formName << std::endl;
    for (int i = 0; i < 3; i++)
	{
		if (Forms[i] == formName)
			return (this->*funcPtrArray[i])(target);;
	}
    std::cout << formName << " doesn't exist. Intern couldn't create Form" << std::endl;
    return NULL;
}
