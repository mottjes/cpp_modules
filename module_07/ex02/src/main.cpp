#include "../include/Array.hpp"

int main(void)
{
	{
		Array <int> a;

		std::cout << "size: " << a.size() << std::endl;
		std::cout << "-------------------" << std::endl;
	}
	{
		Array <int> a(5);

		std::cout << "size: " << a.size() << std::endl;
		try
		{
			a[2] = 42;
			a[3] = -42;
			for (int i = 0; i < 5; i++)
				std::cout << a[i] << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Index out of bounds!" << std::endl;
		}
		std::cout << "-------------------" << std::endl;
	}
	{
		Array <char> a(3);

		std::cout << "size: " << a.size() << std::endl;
		try
		{
			a[0] = 'A';
			a[1] = 'B';
			a[2] = 'C';
			a[3] = -'D';
			for (int i = 0; i < 5; i++)
				std::cout << a[i] << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Index out of bounds!" << std::endl;
		}
		std::cout << "-------------------" << std::endl;

		Array <char> b(3);

		b = a;
		for (int i = 0; i < 3; i++)
			std::cout << b[i] << std::endl;
	}
    return 0;
}
