#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <deque>
#include <utility>

class PmergeMe
{
private:
    std::vector<int>                    _vector;
    std::vector<std::pair<int, int> >    _pairV;
    std::deque<int>                     _deque;
    std::deque<std::pair<int, int> >     _pairD;

    int                 getJacobsthalNumber(int n);
    std::vector<int>    calculateOrderOfInsertation(int pendSize);
    int                 binarySearch(std::vector<int> &mainChain, int low, int high, int target);
    void                sortVector();
    bool                validateInput(int argc, char **argv);
    void                fillVector(int argc, char **argv);
    void                fillDeque(int argc, char **argv);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &rhs);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe &rhs);
    
    void sort(int argc, char **argv);

};