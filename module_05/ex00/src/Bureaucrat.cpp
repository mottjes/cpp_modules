#include "../include/Bureaucrat.hpp"

//	Default Constructor
Bureaucrat::Bureaucrat():   _name("default"), _grade(150)
{
    std::cout << "Bureaucrat Default Constructor called for " << _name << " with the grade of " << _grade << std::endl;
}

//	Parameterized Constructors
Bureaucrat::Bureaucrat(const std::string name):	_name(name), _grade(150)
{
	std::cout << "Bureaucrat Constructor called for " << _name << " with the grade of " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(int	grade):	_name("default")
{
	std::cout << "Bureaucrat Constructor called for " << _name << " with the grade of " << grade << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name, int grade):	_name(name), _grade(grade)
{
	std::cout << "Bureaucrat Constructor called for " << _name << " with the grade of " << grade << std::endl;
	this->setGrade(grade);
}

//	Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &rhs):	_name(rhs.getName())
{
    std::cout << "Bureaucrat Copy Constructor called for " << _name << " with the grade of " << rhs.getGrade() << std::endl;
    *this = rhs;
}

//	Copy assignment operator
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if (this != &rhs)
        _grade = rhs._grade;
    return *this;
}

//	Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called for " << _name << " with the grade of " << _grade << std::endl;
}

//	Member Functions
const std::string	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade;
}

void	Bureaucrat::incrementGrade(void)
{
	this->setGrade(_grade - 1);
}

void	Bureaucrat::decrementGrade(void)
{
	this->setGrade(_grade + 1);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade();
	return os;
}