#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

#include <iostream>
#include <cstdlib>

Base * 	generate(void)
{
	Base *ptr = NULL;

	srand(time(0));
	switch(rand() % 3)
	{
		case 0:
			ptr = new A();
			break;
		case 1:
			ptr = new B();
			break;
		case 2:
			ptr = new C();
			break;
	}
	return ptr;
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "unkown" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::exception &e)
	{}
	try
	{
		B& b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch (std::exception &e)
	{}
	try
	{
		C& c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch (std::exception &e)
	{}
}

int main(void)
{
	Base *baseptr;

	baseptr = generate();
	identify(baseptr);
	identify(*baseptr);
	delete baseptr;
}