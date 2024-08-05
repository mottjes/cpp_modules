#include "../include/easyfind.hpp"

int main(void)
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
