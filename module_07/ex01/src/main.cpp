#include "../include/iter.hpp"

int main(void)
{
	{
		int arr[] = {1, 2, 3, 4, 5};
	
    	iter(arr, 5, printElement);
		std::cout << std::endl;

		iter(arr, 5, plusFive);
		iter(arr, 5, printElement);
    	std::cout << std::endl;
	}
	{
		char arr[] = {'H', 'E', 'L', 'L', 'O'};

		iter(arr, 5, printElement);
		std::cout << std::endl;

		iter(arr, 5, plusFive);
		iter(arr, 5, printElement);
    	std::cout << std::endl;
	}
	{
		bool arr[] = {true, false, false, true};
	
    	iter(arr, 4, printElement);
		std::cout << std::endl;

		iter(arr, 4, plusFive);
		iter(arr, 4, printElement);
    	std::cout << std::endl;
	}
}