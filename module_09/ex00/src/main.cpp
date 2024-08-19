#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
		return (std::cerr << "Error: Wrong Arguments" << std::endl, 1);
    try
    {
        BitcoinExchange bitcoin;

        bitcoin.handleInput(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

