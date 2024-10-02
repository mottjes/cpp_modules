#include "../include/Array.hpp"

struct complex_array
{
    int     a;
    char    b;
};

int main(void)
{
	Array <int> a;

	std::cout << "size: " << a.size() << std::endl;
	std::cout << "-------------------" << std::endl;

	Array <int> b(5);

	std::cout << "size: " << b.size() << std::endl;
	try
	{
		b[2] = 42;
		b[3] = -42;
		for (int i = 0; i < 5; i++)
			std::cout << b[i] << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Index out of bounds!" << std::endl;
	}
	std::cout << "-------------------" << std::endl;
	
	Array <char> c(3);
	std::cout << "size: " << c.size() << std::endl;
	try
	{
		c[0] = 'A';
		c[1] = 'B';
		c[2] = 'C';
		for (int i = 0; i < 5; i++)
			std::cout << c[i] << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Index out of bounds!" << std::endl;
	}
	std::cout << "-------------------" << std::endl;

	Array <char> d(3);

	d = c;
	for (int i = 0; i < 3; i++)
		std::cout << d[i] << std::endl;
    
    std::cout << "-------------------" << std::endl;
    Array <complex_array> e(3);

    e[0].a = 10;
    e[1].b = 'C';
    e[1].a = 42;
    std::cout << "complex size: " << e.size() << std::endl;
    for (size_t i = 0; i < e.size(); i++)
        std::cout <<  e[i].a << " " << e[i].b << std::endl;


    return 0;
}
