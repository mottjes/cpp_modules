#ifndef AAFORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string   _name;
    bool                _signed;
    const   int         _gradeToSign;
    const   int         _gradeToExecute;

public:
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

    AForm();
	AForm(const std::string name);
	AForm(const int gradeToSign, const int gradeToExecute);
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
    AForm(const AForm &rhs);
    ~AForm();
    AForm&	operator=(const AForm &rhs);

    std::string	getName() const;
    bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void		beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
