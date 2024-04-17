#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	std::ifstream	in_file;
	std::ofstream	out_file;
	std::string		line;

	if (argc != 4)
		return std::cout << "Wrong Arguments: <filename> <string1> <string2>" << std::endl, 0;

	in_file.open(argv[1]);
    if (in_file.fail() )
        return std::cerr << "Error opening files." << std::endl, 1;

	out_file.open((std::string(argv[1]) + ".replace").c_str());
	if (out_file.fail())
		return std::cerr << "Error opening files." << std::endl, 1;

    while (std::getline(in_file, line)) {
        out_file << line << std::endl;
    }

    in_file.close();
    out_file.close();

    return 0;
}