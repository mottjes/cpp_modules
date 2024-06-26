#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{

public:
    Intern();
    Intern(const Intern &rhs);
    Intern&	operator=(const Intern &rhs);
    ~Intern();

    AForm*   createShrubberyCreationForm(std::string target);
    AForm*   createRobotomyRequestForm(std::string target);
    AForm*   createPresidentalPardonForm(std::string target);
    AForm* makeForm(std::string formName,std::string target);

};

#endif