#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    const std::string	_name;
    int					_grade;

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

	Bureaucrat();
	Bureaucrat(const Bureaucrat &rhs);
	Bureaucrat(const std::string name);
	Bureaucrat(int	grade);
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();
	Bureaucrat&	operator=(const Bureaucrat &rhs);

	const std::string	getName() const;
	int					getGrade() const;
	void				setGrade(int grade);

	void	incrementGrade();
	void	decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
