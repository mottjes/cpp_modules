#include "../include/easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
    {
        std::vector<int> numbers;

	    numbers.push_back(1);
	    numbers.push_back(5);
	    numbers.push_back(6);
	    numbers.push_back(8);
	    numbers.push_back(11);

	    std::vector<int>::iterator it;

	    try
	    {
	    	it = easyfind(numbers, 5);
	    	std::cout << *it << " found" << std::endl;
	    }
	    catch(std::exception &e)
	    {
	    	 std::cerr << e.what() << std::endl;
	    }
    
	    try
	    {
	    	it = easyfind(numbers, 15);
	    	std::cout << *it << " found" << std::endl;
	    }
	    catch(std::exception &e)
	    {
	    	std::cerr << e.what() << std::endl;
	    }
    }
	{
        std::list<int>  numbers;

        numbers.push_back(1);
        numbers.push_back(14);
        numbers.push_back(3535);

        std::list<int>::iterator it;
        try
	    {
	    	it = easyfind(numbers, 3535);
	    	std::cout << *it << " found" << std::endl;
	    }
	    catch(std::exception &e)
	    {
	    	 std::cerr << e.what() << std::endl;
	    }
    
	    try
	    {
	    	it = easyfind(numbers, 15);
	    	std::cout << *it << " found" << std::endl;
	    }
	    catch(std::exception &e)
	    {
	    	std::cerr << e.what() << std::endl;
	    }
    }
}
