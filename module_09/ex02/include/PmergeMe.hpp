#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
#include <map>

class PmergeMe
{
private:
    std::vector<int>    _vector;
    std::deque<int>     _deque;

    void    _fillVector(char **argv);
    void    _fillDeque(char **argv);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &rhs);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe &rhs);

    void sort(int argc, char **argv);

};
