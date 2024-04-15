#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook book;
	std::string cmd;

	std:: cout << "~ Welcome to the Awesome PhoneBook ~" << std::endl;
	while (1)
	{
		std::cout << "Enter a command (ADD / SEARCH / EXIT) > ";
		std::cin.clear();
		cmd.clear();
		std::getline (std::cin, cmd);
		if (cmd == "ADD")
			book.add();
		else if (cmd == "SEARCH")
			book.search();
		else if (cmd == "EXIT" || std::cin.eof())
			return(0);
		else
			std::cout << "Wrong Input!" << std::endl;
	}
}
