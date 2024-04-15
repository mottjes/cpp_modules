#ifndef PHONEBOOK_HPP
#define	PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact _contacts[8];
	int		_addedContacts;
	int		_i;

public:
	PhoneBook();
	void	add(void);
	void	search(void) const;
};

#endif