#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <deque>
#include <utility>

class PmergeMe
{
private:
    std::vector<int>                    _vector;
    std::vector<std::pair<int, int> >   _vectorPairs;
    std::deque<int>                     _deque;
    std::deque<std::pair<int, int> >    _dequePairs;
    int                                 _comparisonsVector;
    int                                 _comparisonsDeque;

    void                printAfterSorting();
    void                fillVector(int argc, char **argv);
    void                fillDeque(int argc, char **argv);
    void                mergeInsertionVector();
    void                mergeInsertionDeque();
    void                buildVectorPairs();
    void                buildDequePairs();
    template<typename T>
    void                recursiveInsertionSort(T& pairs, int n);
    template<typename T>
    int                 binarySearch(T &mainChain, int low, int high, int target);
    template<typename T>
    void                calculateOrderOfInsertation(T &order, int pendSize);
    int                 getJacobsthalNumber(int n);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &rhs);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe &rhs);
    
    void sort(int argc, char **argv);

};
