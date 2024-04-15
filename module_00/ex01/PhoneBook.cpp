#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_i = 0;
	this->_addedContacts = 0;
}

void	PhoneBook::add(void)
{
	if (this->_i == 8)
		this->_i = 0;
	this->_contacts[this->_i].init(this->_i);
	std:: cout << "Added Contact in place[" << this->_i + 1 << "/8]" << std::endl;
	this->_i++;
	if (this->_addedContacts < 8)
		this->_addedContacts++;
}

void	PhoneBook::search(void) const
{
	std::string input;

	std::cout << std::setw(10) << std::right << "index" << "|";
	std::cout << std::setw(10) << std::right << "firstName" << "|";
	std::cout << std::setw(10) << std::right << "lastName" << "|";
	std::cout << std::setw(10) << std::right << "nickName" << "|" << std::endl;
	for(int i = 0; i < _addedContacts; i++)
		this->_contacts[i].printRow();
	std::cout << "Select an index: ";
	std::cin.clear();
	input.clear();
	std::getline (std::cin, input);
	if (std::cin.eof())
		exit(0);
	if (input.size() == 1 && input[0] >= '1' && input[0] <= '8' && input[0] - 1 - '0' < this->_addedContacts)
		this->_contacts[input[0] - 1 - '0'].display();
	else
		std::cout << "Invalid index!" << std::endl;
}
