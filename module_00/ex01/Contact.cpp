#include "Contact.hpp"

std::string Contact::_getInput(std::string string) const
{
	std::string input;
	bool		valid;

	valid = false;
	std::cout << string;
	while (!valid)
	{
		std::cin.clear();
		std::getline (std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl; 
			exit(0);
		}
		if (!input.empty())
		{
			for (int i = 0; i < (int)input.length(); i++)
			{
				if ((input[i] >= 'A' && input[i] <= 'z') || (input[i] >= '0' && input[i] <= '9'))
					valid = true;
			}
		}
		if (!valid)
			std::cout << "Invalid Input. Please enter again: ";
	}
	return input;
}		

void	Contact::init(void)
{
	this->_firstName = _getInput("Please enter your first name: ");
	this->_lastName = _getInput("Please enter your last name: ");
	this->_nickname = _getInput("Please enter your nickname: ");
	this->_phoneNumber = _getInput("Please enter your phone number: ");
	this->_darkestSecret = _getInput("Please enter your darkest secret: ");
}

void	Contact::display(void) const
{
	if (this->_firstName.length() > 10)
		std::cout << std::setw(10) << std::right << std::string(this->_firstName, 0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << std::right << std::string(this->_firstName, 0, 10) << "|";
	if (this->_lastName.length() > 10)
    	std::cout << std::setw(10) << std::right << std::string(this->_lastName, 0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << std::right << std::string(this->_lastName, 0, 10) << "|";
	if (this->_nickname.length() > 10)
		std::cout << std::setw(10) << std::right << std::string(this->_nickname, 0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << std::right << std::string(this->_nickname, 0, 10) << "|";
	if (this->_nickname.length() > 10)
		std::cout << std::setw(10) << std::right << std::string(this->_phoneNumber, 0, 9) << "." << "|" << std::endl;
	else
    	std::cout << std::setw(10) << std::right << std::string(this->_phoneNumber, 0, 10) << "|" << std::endl;
}	
