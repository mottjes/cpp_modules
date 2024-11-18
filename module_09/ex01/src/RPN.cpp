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
    float   a, b;

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
                std::cerr << "Error: invalid expression" << std::endl;
                return ;
            }
            b = _stack.top();
            _stack.pop();
            a = _stack.top();
            _stack.pop();
            if (input[i] == '+')
                _stack.push(a + b);
            else if (input[i] == '-')
                _stack.push(a - b);
            else if (input[i] == '*')
                _stack.push(a * b);
            else if (input[i] == '/')
                _stack.push(a / b);
        }
        else
        {
            std::cerr << "Error: invalid character" << std::endl;
            return ;
        }
    }
    if (_stack.size() != 1)
        std::cerr << "Error: invalid expression" << std::endl;
    else
        std::cerr << _stack.top() << std::endl;
}
