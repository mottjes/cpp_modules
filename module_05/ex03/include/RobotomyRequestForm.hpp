#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    const std::string   _target;

    RobotomyRequestForm();

public:
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &rhs);
    RobotomyRequestForm&	operator=(const RobotomyRequestForm &rhs);
    ~RobotomyRequestForm();

    void    execute(Bureaucrat const &executor) const;

};

#endif