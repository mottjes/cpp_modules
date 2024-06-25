#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm Constructor called with target : " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs)
{
    std::cout << "RobotomyRequestForm Copy Constructor called for " << std::endl;
    *this = rhs;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    (void)rhs;
    return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    else
    {
        std::srand(std::time(NULL));
        int random_value = std::rand();
        if (random_value % 2)
            std::cout <<  _target << " has been robotomized successfully" << std::endl;
        else
            std::cout << "robotomy failed on " << _target << std::endl;
    }
}