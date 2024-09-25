#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm Constructor called with target : " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : AForm(rhs)
{
    std::cout << "ShrubberyCreationForm Copy Constructor called for " << std::endl;
    *this = rhs;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    (void)rhs;
    return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    else
    {
        std::ofstream outFile((_target + "_shrubbery").c_str());

        if(outFile.is_open())
        {
        	for (int i = 0; i < 3; i++)
        	{
            	outFile <<
			"         *" << std::endl <<
			"        ***" << std::endl <<
			"         *" << std::endl <<
			"        ***" << std::endl <<
			"      ********" << std::endl <<
			"    ***********" << std::endl <<
			"       *****" << std::endl <<
			"      *******" << std::endl <<
			"    **********" << std::endl <<
			"  **************" << std::endl <<
			"      ******" << std::endl <<
			"     *********" << std::endl <<
			"  **************" << std::endl <<
			" ****************" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl << std::endl;
        	}
        	outFile.close();
    	}
    	else
        	std::cerr << "Failed to create the file in the working directory." << std::endl;
    }
}
