#pragma once

#include <iostream>
#include <stack>
#include <cstring>

class RPN
{
private:
    std::stack<float>    _stack;

public:
    RPN();
    RPN(const RPN &rhs);
    ~RPN();
    RPN& operator=(const RPN &rhs);

    void    calculate(std::string input);

};