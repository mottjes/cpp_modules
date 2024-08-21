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
        _deque = rhs._deque;
    }
    return *this;
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

void recursiveInsertionSortVector(std::vector<std::pair<int, int> >& arr, int n)
{
    // Base case: if the array size is 1 or less, it's already sorted
    if (n <= 1)
        return;

    // Sort the first n-1 elements
    recursiveInsertionSortVector(arr, n - 1);

    // Insert the last element at the correct position
    std::pair<int, int> last = arr[n - 1];
    int j = n - 2;

    // Move elements of arr[0..n-2], that are greater than 'last',
    // to one position ahead of their current position
    while (j >= 0 && arr[j].second > last.second) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int PmergeMe::getJacobsthalNumber(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Using a vector to store computed Jacobsthal numbers
    std::vector<int> jacobsthalNumbers(n + 1);
    jacobsthalNumbers[0] = 0; // J(0)
    jacobsthalNumbers[1] = 1; // J(1)

    for (int i = 2; i <= n; ++i) {
        jacobsthalNumbers[i] = jacobsthalNumbers[i - 2] + 2 * jacobsthalNumbers[i - 1];
    }

    return jacobsthalNumbers[n];
}

std::vector<int>    PmergeMe::calculateOrderOfInsertation(int pendSize)
{
    std::vector<int>    order;
    int                 jacobsthalnumber;
    int                 highest = 2;

    for(int i = 0; i < pendSize; i++)
    {
        jacobsthalnumber = getJacobsthalNumber(i + 2);
        for (int j = jacobsthalnumber; j > highest; j--)
            order.push_back(jacobsthalnumber);
        highest = jacobsthalnumber;
    }
    return order;
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
    (void)struggler;
    // puts list into pairs
    int nbr1, nbr2;
    while(_vector.size())
    {
        nbr1 = _vector.back();
        _vector.pop_back();
        nbr2 = _vector.back();
        _vector.pop_back();
        _pairV.push_back(std::make_pair(nbr1 , nbr2));
    }
    // sorts each pair
    for (std::vector<std::pair<int, int> >::iterator it = _pairV.begin(); it != _pairV.end(); it++)
    {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }
    // sorts pairs by comparing the bigger number
    recursiveInsertionSortVector(_pairV, _pairV.size());
    // build pend and main chain and push first of pend infront of main chain
    std::vector<int>    pend;

    for (int i = _pairV.size() - 1; i > - 1; i--)
    {
        _vector.push_back(_pairV[i].second);
        std::cout << "push to main: " << _pairV[i].second << std::endl;
        pend.push_back(_pairV[i].first);
        std::cout << "push to pend: " << _pairV[i].first << std::endl;
    }
    // _vector.insert(_vector.begin(), pend[0]);
    // pend.erase(pend.begin());

    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
        std::cout << *it << std::endl;
    // //  get right inserition order
    // std::vector<int> insertionOrder = calculateOrderOfInsertation(pend.size());

    // //  binary search for place to insert
    // int place;
    // std::vector<int>::iterator it;
    // for (size_t i = 0; i < insertionOrder.size(); i++)
    // {
    //     place = binarySearch(_vector, 0, _vector.size(), pend[insertionOrder[i]]);
    //     it = _vector.begin();
    //     while (place > 1)
    //     {
    //         it++;
    //         place--;
    //     }
    //     _vector.insert(it, insertionOrder[i]);
    // }
}


int PmergeMe::binarySearch(std::vector<int> &mainChain, int low, int high, int target)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (mainChain[mid] == target) {
            return mid;
        }

        // If x is greater, ignore the left half
        if (mainChain[mid] < target) {
            low = mid + 1;
        }
        // If x is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    // If we reach here, the element was not present
    return high;
}

void    PmergeMe::sort(int argc, char **argv)
{
    if (argc == 2)
        return ;
    if (validateInput(argc, argv) == false)
    {
        std::cout << "Error: wrong Input" << std::endl;
        return ;
    }
    fillVector(argc, argv);
    // fillDeque(argc, argv);
    sortVector();
    // sortDeque();

    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
        std::cout << *it << std::endl;
}