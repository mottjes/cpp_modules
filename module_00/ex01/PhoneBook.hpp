#ifndef PHONEBOOK_HPP
#define	PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact _contacts[8];
	int		_addedContacts;
	int		_i;
	
	void	_addContact(void);
	void	_search(void);
	void	_exit(void);
public:
	PhoneBook();
	void	welcome(void);
};

#endif