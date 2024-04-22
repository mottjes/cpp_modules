#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int level = 0;

	if (argc != 2)
		return std::cout << "[ Probably complaining about insignificant problems ]" << std::endl, 1;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == argv[1])
			level = i + 1;
	}
	switch(level)
	{
		case 1:
			harl.complain("debug");
		case 2:
			harl.complain("info");
		case 3:
			harl.complain("warning");
		case 4:
			harl.complain("error");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
