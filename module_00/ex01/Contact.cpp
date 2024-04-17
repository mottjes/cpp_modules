#include "PhoneBook.hpp"

void	Contact::display(void) const
{
	std::cout << "FirstName: " << this->_firstName << std::endl;
	std::cout << "LastName: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "PhoneNumber: " << this->_phoneNumber << std::endl;
	std::cout << "DarkestSecret: " << this->_darkestSecret << std::endl;
}

static std::string lengthCheck(std::string string)
{
	if (string.length() >= 10)
	{
		string = string.substr(0, 9);
		string += ".";
	}
	return (string);
}

void	Contact::printRow(void) const
{
	std::cout << std::setw(10) << std::right << this->_index + 1 << "|";
	std::cout << std::setw(10) << std::right << lengthCheck(this->_firstName) << "|";
    std::cout << std::setw(10) << std::right << lengthCheck(this->_lastName) << "|";
	std::cout << std::setw(10) << std::right << lengthCheck(this->_nickname) << "|" << std::endl;
}

std::string	Contact::_getInput(std::string string) const
{
	std::string input;
	bool valid;

	valid = false;
	while (!valid)
	{
		std::cout << string;
		std::cin.clear();
		std::getline (std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (!input.empty())
		{
			for (int i = 0; i < (int)input.length(); i++)
			{
				if ((input[i] >= 'A' && input[i] <= 'z') || (input[i] >= '0' && input[i] <= '9'))
					valid = true;
			}
		}
		if (!valid)
			std::cout << "Invalid Input!" << std::endl;
	}
	return input;
}

void	Contact::init(int index)
{
	this->_index = index;
	this->_firstName = _getInput("Please enter first name: ");
	this->_lastName = _getInput("Please enter last name: ");
	this->_nickname = _getInput("Please enter nickname: ");
	this->_phoneNumber = _getInput("Please enter phonenumber: ");
	this->_darkestSecret = _getInput("Please enter darkest secret: ");
}
