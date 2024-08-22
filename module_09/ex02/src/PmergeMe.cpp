#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
    *this = rhs;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {
        _vector = rhs._vector;
        _vectorPairs = rhs._vectorPairs;
        _deque = rhs._deque;
        _dequePairs = rhs._dequePairs;
    }
    return *this;
}

bool    PmergeMe::validateInput(int argc, char **argv)
{
    int i;

    argc--;
    while (argc)
    {
        i = 0;
        while (argv[argc][i] && iswspace(argv[argc][i]))
            i++;
        while (argv[argc][i])
        {
            if (!isdigit(argv[argc][i]))
                return false;
            i++;
        }
        argc--;
    }
    return true;
}

void    PmergeMe::fillVector(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
        _vector.push_back(atoi(argv[i]));
}

void    PmergeMe::fillDeque(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
        _deque.push_back(atoi(argv[i]));
}

void    PmergeMe::printBeforeSorting(int argc, char **argv)
{
    std::cout << "Before: ";
    for (int i = 1; i < argc; i++)
    {
        if (i > 10)
        {
            std::cout << "[...]";
            break ;
        }
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printAfterSorting()
{
    int i = 0;

    std::cout << "After:  ";
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
    {
        i++;
        if (i > 10)
        {
            std::cout << "[...]";
            break ;
        }
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::buildVectorPairs()
{
    int nbr1, nbr2;

    while(_vector.size())
    {
        nbr1 = _vector.back();
        _vector.pop_back();
        nbr2 = _vector.back();
        _vector.pop_back();
        _vectorPairs.push_back(std::make_pair(nbr1 , nbr2));
    }
}

void    PmergeMe::buildDequePairs()
{
    int nbr1, nbr2;

    while(_deque.size())
    {
        nbr1 = _deque.back();
        _deque.pop_back();
        nbr2 = _deque.back();
        _deque.pop_back();
        _dequePairs.push_back(std::make_pair(nbr1 , nbr2));
    }
}

template <typename T>
void    PmergeMe::recursiveInsertionSort(T& pairs, int n)
{
    // Base case: if the array size is 1 or less, it's already sorted
    if (n <= 1)
        return;

    // Sort the first n-1 elements
    recursiveInsertionSort(pairs, n - 1);

    // Insert the last element at the correct position
    std::pair<int, int> last = pairs[n - 1];
    int j = n - 2;

    // Move elements of pairs[0..n-2], that are greater than 'last',
    // to one position ahead of their current position
    while (j >= 0 && pairs[j].second > last.second)
    {
        pairs[j + 1] = pairs[j];
        j--;
    }
    pairs[j + 1] = last;
}

template <typename T>
void    PmergeMe::calculateOrderOfInsertation(T &order, int pendSize)
{
    int                 jacobsthalNumber;
    int                 highest = 1;
    int                 n = 3;

    for(int i = 0; i < pendSize; n++)
    {
        jacobsthalNumber = getJacobsthalNumber(n);
        for (int j = 0; (jacobsthalNumber - j) > highest; j++)
        {
            order.push_back(jacobsthalNumber - j);
            i++;
        }
        highest = jacobsthalNumber;
        if (highest > pendSize)
            break ;
    }
}

template <typename T>
int PmergeMe::binarySearch(T &mainChain, int low, int high, int target)
{
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;

        // Check if target is present at mid
        if (mainChain[mid] == target)
            return mid;
        // If target is greater, ignore the left half
        if (mainChain[mid] < target)
            low = mid + 1;
        // If target is smaller, ignore the right half
        else
            high = mid - 1;
    }
    // If we reach here, the element was not present
    return high;
}

int PmergeMe::getJacobsthalNumber(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    int prev = 0;
    int curr = 1;
    
    for (int i = 2; i <= n; ++i)
    {
        int next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }
    return curr;
}

void    PmergeMe::sortVector()
{
    int struggler = - 1;
    // saves struggler for later
    if (_vector.size() % 2)
    {
        struggler = _vector.back();
        _vector.pop_back();
    }
    // puts list into pairs
    buildVectorPairs();
    // sorts each pair
    for (std::vector<std::pair<int, int> >::iterator it = _vectorPairs.begin(); it != _vectorPairs.end(); it++)
    {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }
    // sorts pairs by comparing the bigger number
    recursiveInsertionSort(_vectorPairs, _vectorPairs.size());
    // build pend and main chain and push first of pend infront of main chain
    std::vector<int>    pend;

    for (size_t i = 0; i < _vectorPairs.size(); i++)
    {
        _vector.push_back(_vectorPairs[i].second);
        pend.push_back(_vectorPairs[i].first);
    }
    //push smaller part of smallest pair infornt of main chain
    _vector.insert(_vector.begin(), pend[0]);

    //  get right insertion order
    std::vector<int> insertionOrder;
    calculateOrderOfInsertation(insertionOrder, pend.size());

    //  binary search for place to insert
    int place;
    std::vector<int>::iterator it;

    for (size_t i = 0; i < insertionOrder.size(); i++)
    {
        if (size_t(insertionOrder[i]) <= pend.size())
        {
            place = binarySearch(_vector, 0, _vector.size(), pend[insertionOrder[i] - 1]);
            it = _vector.begin();
            while (place > - 1)
            {
                it++;
                place--;
            }
            _vector.insert(it, pend[insertionOrder[i] - 1]);
        }
    }
    // push struggler if there
    if (struggler != - 1)
    {
        if (struggler > _vector.back())
            _vector.push_back(struggler);
        else
        {
            place = binarySearch(_vector, 0, _vector.size(), struggler);
            it = _vector.begin();
            while (place > - 1)
            {
                it++;
                place--;
            }
            _vector.insert(it, struggler);
        }
    }
}

void    PmergeMe::sortDeque()
{
    int struggler = - 1;
    // saves struggler for later
    if (_deque.size() % 2)
    {
        struggler = _deque.back();
        _deque.pop_back();
    }
    (void)struggler;
    // puts list into pairs
    buildDequePairs();
    // sorts each pair
    for (std::deque<std::pair<int, int> >::iterator it = _dequePairs.begin(); it != _dequePairs.end(); it++)
    {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }
    // sorts pairs by comparing the bigger number
    recursiveInsertionSort(_dequePairs, _dequePairs.size());
    // build pend and main chain and push first of pend infront of main chain
    std::deque<int>    pend;

    for (size_t i = 0; i < _dequePairs.size(); i++)
    {
        _deque.push_back(_dequePairs[i].second);
        pend.push_back(_dequePairs[i].first);
    }
    //push smaller part of smallest pair infornt of main chain
    _deque.insert(_deque.begin(), pend[0]);

    //  get right insertion order
    std::deque<int> insertionOrder;
    calculateOrderOfInsertation(insertionOrder, pend.size());

    //  binary search for place to insert
    int place;
    std::deque<int>::iterator it;

    for (size_t i = 0; i < insertionOrder.size(); i++)
    {
        if (size_t(insertionOrder[i]) <= pend.size())
        {
            place = binarySearch(_deque, 0, _deque.size(), pend[insertionOrder[i] - 1]);
            it = _deque.begin();
            while (place > - 1)
            {
                it++;
                place--;
            }
            _deque.insert(it, pend[insertionOrder[i] - 1]);
        }
    }
    // push struggler if there
    if (struggler != - 1)
    {
        if (struggler > _deque.back())
            _deque.push_back(struggler);
        else
        {
            place = binarySearch(_deque, 0, _deque.size(), struggler);
            it = _deque.begin();
            while (place > - 1)
            {
                it++;
                place--;
            }
            _deque.insert(it, struggler);
        }
    }
}

void    PmergeMe::sort(int argc, char **argv)
{
    clock_t start , end;
    double  elapsedTime;

    if (argc == 2)
        return ;
    if (validateInput(argc, argv) == false)
    {
        std::cout << "Error: wrong Input" << std::endl;
        return ;
    }
    printBeforeSorting(argc, argv);
    start = clock();
    fillVector(argc, argv);
    sortVector();
    end = clock();
    elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    printAfterSorting();
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector container: " << elapsedTime << " us" << std::endl;

    start = clock();
    fillDeque(argc, argv);
    sortDeque();
    end = clock();
    elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::deque container: " << elapsedTime << " us" << std::endl;
}
