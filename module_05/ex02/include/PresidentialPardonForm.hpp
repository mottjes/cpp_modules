#ifndef PRERSIDENTIALPARDONFORM_HPP
#define PRERSIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    const std::string   _target;

    PresidentialPardonForm();

public:
    PresidentialPardonForm(const std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &rhs);
    PresidentialPardonForm&	operator=(const PresidentialPardonForm &rhs);
    ~PresidentialPardonForm();

    void    execute(Bureaucrat const &executor) const;

};

#endif