#ifndef CONTACT_HPP
#define	CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
	int			_index;

	std::string	_getInput(std::string string) const;
public:
	void	init(int index);
	void	printRow(void) const;
	void	display(void) const;
};

#endif