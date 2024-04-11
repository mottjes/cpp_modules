#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_i = 0;
	this->_addedContacts = 0;
	this->welcome();
}

void	PhoneBook::welcome(void)
{
	std::string	input;

	std:: cout << "Welcome to the Awesome PhoneBook" << std::endl;
	while (1)
	{
		std::cout << "Enter a command (ADD / SEARCH / EXIT) > ";
		std::cin.clear();
		input.clear();
		std::getline (std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl; 
			exit(0);
		}
		else if (!input.compare("ADD"))
			this->_addContact();
		else if (!input.compare("SEARCH"))
			this->_search();
		else if (!input.compare("EXIT"))
			this->_exit();
	}
}

void	PhoneBook::_search(void)
{
	std::string	input;

	std::cout << "___________________________________________" << std::endl;
	std::cout << std::setw(10) << std::right << "index" << "|";
	std::cout << std::setw(10) << std::right << "firstName" << "|";
	std::cout << std::setw(10) << std::right << "lastName" << "|";
	std::cout << std::setw(10) << std::right << "nickName" << "|" << std::endl;
	std::cout <<  "__________|__________|__________|__________|" <<std::endl;
	for (int i = 0; i < this->_addedContacts; i++)
		this->_contacts[i].display();

	// getting mor infos
	std::cout << "Select an index: ";
	std::cin.clear();
	input.clear();
	std::getline (std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl; 
		exit(0);
	}
	if (input.size() == 1 && input[0] >= '1' && input[0] <= '8' && input[0] - 1 - '0' < this->_addedContacts)
		this->_contacts[input[0] - 1 - '0'].print();
	else
		std::cout << "Invalid index!" << std::endl;
}

void	PhoneBook::_addContact(void)
{
	if (this->_i == 8)
		this->_i = 0;
	this->_contacts[this->_i].init(this->_i);
	std:: cout << "Added Contact in place[" << this->_i + 1 << "/8]" << std::endl;
	this->_i++;
	if (this->_addedContacts < 8)
		this->_addedContacts++;
}

void	PhoneBook::_exit(void)
{
	std::cout << "Bye Bye" << std::endl;
	exit(0);
}
