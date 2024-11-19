#include "../include/PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc <= 2)
        return 1;
    try
    {
        PmergeMe    sorter;
    
        sorter.sort(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
