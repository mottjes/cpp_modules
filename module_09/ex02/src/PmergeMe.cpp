#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
    *this = rhs;
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

static void validate_input(char **argv)
{
    std::vector<int> arr;

    // check for other than positive numbers
    for(int i = 1; argv[i]; i++)
    {
        for(int j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
                throw std::invalid_argument("arguments is not an digit");
        }
        arr.push_back(atoi(argv[i]));
    }
    // check for duplicates
    std::sort(arr.begin(), arr.end());
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            throw std::invalid_argument("duplicate found");
    }
}

static void printBefore(char **argv)
{
    std::cout << "Before: ";
    for (int i = 1; argv[i]; i++)
    {
        // if (i > 10)
        // {
        //     std::cout << "[...]";
        //     break ;
        // }
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
static void printAfter(const T& container)
{
    int i = 0;

    std::cout << "After: ";
    for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
    {
        i++;
        // if (i > 10)
        // {
        //     std::cout << "[...]";
        //     break ;
        // }
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

static int getJacobsthalNumber(int n)
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

template <typename T>
static void calculateOrderOfInsertation(T &order, int size)
{
    int jacobsthalNumber;
    int highest = 1;
    int n = 3;

    for(int i = 0; i < size; n++)
    {
        jacobsthalNumber = getJacobsthalNumber(n);
        if (jacobsthalNumber > size + 1)
            jacobsthalNumber = size + 1;
        for (int j = 0; (jacobsthalNumber - j) > highest; j++)
        {
            order.push_back(jacobsthalNumber - j);
            i++;
        }
        highest = jacobsthalNumber;
        if (highest > size)
            break ;
    }
}

static std::vector<int> mergeInsertionVector(std::vector<int> &d)
{
    if (d.size() <= 1)
        return d;

    int n = d.size();

    // Step 1: Pairwise comparison
    std::vector<int> a, b;

    // Split into larger and smaller half
    for (int i = 0; i < n / 2; i++)
    {
        if (d[i] > d[i + n / 2])
        {
            a.push_back(d[i]);
            b.push_back(d[i + n / 2]);
        }
        else
        {
            a.push_back(d[i + n / 2]);
            b.push_back(d[i]);
        }
    }

    // Handle odd-amount of numbers 
    if (n % 2 == 1)
        b.push_back(d[n - 1]);


    // Step 2: Recursion and Renaming
    std::multimap<int, int> m;

    for (int i = 0; i < n / 2; i++)
        m.insert(std::make_pair(a[i], b[i])); // Store mapping

    a = mergeInsertionVector(a);
    
    // Step 3: Insertion
    std::vector<int> result;

    // Restore Mapping
    for (int i = 0; i < n / 2; i++)
        b[i] = m.find(a[i])->second;

    result.push_back(b[0]);
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
        result.push_back(*it);

    std::vector<int> insertion_order;

    calculateOrderOfInsertation(insertion_order, (b.size() - 1));
    for (size_t i = 1; i < b.size(); i++)
    {
        std::vector<int>::iterator it = std::lower_bound(result.begin(), result.end(), b[insertion_order[i - 1] - 1]);
        result.insert(it, b[insertion_order[i - 1] - 1]);
    }

    return result;
}


static std::deque<int> mergeInsertionDeque(std::deque<int> &d)
{
    if (d.size() <= 1)
        return d;

    int n = d.size();

    // Step 1: Pairwise comparison
    std::deque<int> a, b;

    // Split into larger and smaller half
    for (int i = 0; i < n / 2; i++)
    {
        if (d[i] > d[i + n / 2])
        {
            a.push_back(d[i]);
            b.push_back(d[i + n / 2]);
        }
        else
        {
            a.push_back(d[i + n / 2]);
            b.push_back(d[i]);
        }
    }

    // Handle odd-amount of numbers 
    if (n % 2 == 1)
        b.push_back(d[n - 1]);

    // Step 2: Recursion and Renaming
    std::multimap<int, int> m;

    for (int i = 0; i < n / 2; i++)
        m.insert(std::make_pair(a[i], b[i])); // Store mapping

    a = mergeInsertionDeque(a);
    
    // Step 3: Insertion
    std::deque<int> result;

    // Restore Mapping
    for (int i = 0; i < n / 2; i++)
        b[i] = m.find(a[i])->second;

    result.push_back(b[0]);
    for (std::deque<int>::iterator it = a.begin(); it != a.end(); it++)
        result.push_back(*it);

    std::deque<int> insertion_order;

    calculateOrderOfInsertation(insertion_order, (b.size() - 1));
    for (size_t i = 1; i < b.size(); i++)
    {
        std::deque<int>::iterator it = std::lower_bound(result.begin(), result.end(), b[insertion_order[i - 1] - 1]);
        result.insert(it, b[insertion_order[i - 1] - 1]);
    }

    return result;
}

void PmergeMe::_fillVector(char **argv)
{
    for(int i = 1; argv[i]; i++)
    {
        for(int j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
                throw std::invalid_argument("arguments is not an digit");
        }
        _vector.push_back(atoi(argv[i]));
    }
}

void PmergeMe::_fillDeque(char **argv)
{
    for(int i = 1; argv[i]; i++)
    {
        for(int j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
                throw std::invalid_argument("arguments is not an digit");
        }
        _deque.push_back(atoi(argv[i]));
    }
}

// template<typename T>
// static void checkSorted(T &container)
// {
//     bool    sorted = true;

//     for (size_t i = 0; i < container.size(); i++)
//     {
//         int prev = -1;
//         if (prev >= container[i])
//             sorted = false;
//         prev = container[i];
//     }
//     if (sorted)
//         std::cout << "Is sorted" << std::endl;
//     else
//         std::cout << "Is not Sorted !!!" << std::endl;
// }

void    PmergeMe::sort(int argc, char **argv)
{
    if (argc <= 2)
        return ;
    
    validate_input(argv);
    double  time_vector_us, time_deque_us;
    clock_t start, end;

    // ===== Vector ===== //
    start = clock();
    _fillVector(argv);
    _vector = mergeInsertionVector(_vector);
    end = clock();
    time_vector_us = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    // ===== Deque ===== //
    start = clock();
    _fillDeque(argv);
    _deque = mergeInsertionDeque(_deque);
    end = clock();
    time_deque_us = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    // === Printing ==== //
    printBefore(argv);
    printAfter(_vector);
    // printAfter(_deque);
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector container: " << time_vector_us << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque container: " << time_deque_us << " us" << std::endl;

    // checkSorted(_vector);
    // checkSorted(_deque);
}
