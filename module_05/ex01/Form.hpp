#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string   _name;
    bool                _signed;
    const   int         _gradeToSign;
    const   int         _gradeToExecute;

public:
    Form();
	Form(const std::string name);
	Form(const int gradeToSign, const int gradeToExecute);
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
    Form(const Form &rhs);
    ~Form();
    Form&	operator=(const Form &rhs);

    std::string	getName() const;
    bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void		beSigned(Bureaucrat &bureacrat);

	class	GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
