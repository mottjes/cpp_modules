#include <iostream>
#include <fstream>
#include <string>

std::string	replace(char **argv, std::string line)
{
	std::size_t	found;

	found = 0;
	while (1)
	{
		found = line.find(argv[2], found);
		if (found != std::string::npos)
		{
			line.erase(found, std::string(argv[2]).size());
			line.insert(found, argv[3]);
			return line;
		}
		else
			return line;
	}
}

int	main(int argc, char **argv)
{
	std::ifstream	in_file;
	std::ofstream	out_file;
	std::string		line;

	if (argc != 4)
		return std::cout << "Wrong Arguments: <filename> <string1> <string2>" << std::endl, 0;
	in_file.open(argv[1]);
    if (in_file.fail())
	{
		std::cerr << "Error opening files." << std::endl;
		return 1;
	}
	out_file.open((std::string(argv[1]) + ".replace").c_str());
	if (out_file.fail())
	{
		std::cerr << "Error opening files." << std::endl;
		return 1;
	}
    while (std::getline(in_file, line))
	{
		line = replace(argv, line);
		out_file << line << std::endl;
	} 
    in_file.close();
	out_file.close();
    return 0;
}