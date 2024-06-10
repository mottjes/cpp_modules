#include "Form.hpp"

Form::Form():   _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const std::string name): _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form Constructor called for Form with name: " << _name << std::endl;
}

Form::Form(const int gradeToSign, const int gradeToExecute): _name("default"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form Constructor called for Form with name: " << _name << std::endl;
    if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();	
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form Constructor called for Form with name: " << _name << std::endl;
    if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();	
}

Form::Form(const Form &rhs):	_name(rhs.getName()), _gradeToSign(rhs.getGradeToSign()), _gradeToExecute(rhs.getGradeToExecute())
{
    std::cout << "Form Copy Constructor called for " << _name << std::endl;
    *this = rhs;
}

Form::~Form()
{
    std::cout << "Form Destructor called for " << _name << std::endl;
}

Form&	Form::operator=(const Form &rhs)
{
    if (this != &rhs)
        _signed = rhs._signed;
    return *this;
}

std::string Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void    Form::beSigned(Bureaucrat &bureacrat)
{
    if (bureacrat.getGrade() <= _gradeToSign)
        _signed = true;
    else 
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form name: " << form.getName() << std::endl 
    << "Signed: " << form.getSigned() << std::endl 
    << "Grade to Sign: " << form.getGradeToSign() << std::endl 
    << "Grade to execute: " << form.getGradeToExecute();
	return os;
}