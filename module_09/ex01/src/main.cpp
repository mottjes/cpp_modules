#include "../include/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: wrong input" << std::endl;
        return 1;
    }
    RPN rpn;

    rpn.calculate(std::string(argv[1]));
    return 0;
}