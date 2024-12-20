#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    const std::string   _target;

    ShrubberyCreationForm();

public:
    ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
    ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &rhs);
    ~ShrubberyCreationForm();

    void    execute(Bureaucrat const &executor) const;

};

#endif