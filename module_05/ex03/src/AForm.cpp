#include "../include/AForm.hpp"

AForm::AForm():   _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form Default Constructor called" << std::endl;
}

AForm::AForm(const std::string name): _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form Constructor called for Form with name: " << _name << std::endl;
}

AForm::AForm(const int gradeToSign, const int gradeToExecute): _name("default"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form Constructor called for Form with name: " << _name << std::endl;
    if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();	
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form Constructor called for Form with name: " << _name << std::endl;
    if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();	
}

AForm::AForm(const AForm &rhs):	_name(rhs.getName()), _gradeToSign(rhs.getGradeToSign()), _gradeToExecute(rhs.getGradeToExecute())
{
    std::cout << "Form Copy Constructor called for " << _name << std::endl;
    *this = rhs;
}

AForm::~AForm()
{
    std::cout << "Form Destructor called for " << _name << std::endl;
}

AForm&	AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
        _signed = rhs._signed;
    return *this;
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void    AForm::beSigned(Bureaucrat &bureacrat)
{
    if (bureacrat.getGrade() <= _gradeToSign)
        _signed = true;
    else 
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form needs to be signed before executing!");
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form name: " << form.getName() << std::endl 
    << "Signed: " << form.getSigned() << std::endl 
    << "Grade to Sign: " << form.getGradeToSign() << std::endl 
    << "Grade to execute: " << form.getGradeToExecute();
	return os;
}