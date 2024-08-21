#include "../include/PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: no input" << std::endl;
        return 1;
    }
    PmergeMe pmergeMe;
    
    pmergeMe.sort(argc, argv);
    return 0;
}