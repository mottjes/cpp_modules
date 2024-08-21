#include "../include/RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &rhs)
{
    *this = rhs;
}

RPN::~RPN()
{
}

RPN& RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
        _stack = rhs._stack;
    return *this;
}

void RPN::calculate(std::string input)
{
    float   nbr1, nbr2;

    for (size_t i = 0; i < input.size(); i++)
    {
        if (iswspace(input[i]))
            continue ;
        else if (isdigit(input[i]))
            _stack.push(input[i] - '0');
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            if (_stack.size() < 2)
            {
                std::cout << "Error: invalid expression" << std::endl;
                return ;
            }
            nbr1 = _stack.top();
            _stack.pop();
            nbr2 = _stack.top();
            _stack.pop();
            if (input[i] == '+')
                _stack.push(nbr2 + nbr1);
            else if (input[i] == '-')
                _stack.push(nbr2 - nbr1);
            else if (input[i] == '*')
                _stack.push(nbr2 * nbr1);
            else if (input[i] == '/')
                _stack.push(nbr2 / nbr1);
        }
        else
        {
            std::cout << "Error: invalid character" << std::endl;
            return ;
        }
    }
    if (_stack.size() != 1)
        std::cout << "Error: invalid expression" << std::endl;
    else
        std::cout << _stack.top() << std::endl;
}
