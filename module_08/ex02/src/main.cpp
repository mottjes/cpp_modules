#include "../include/MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "-----------list-------------" << std::endl;

	std::list <int> l;

	l.push_back(5);
	l.push_back(17);

	std::cout << l.back() << std::endl;

	l.pop_back();

	std::cout << l.size() << std::endl;

	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	//[...]
	l.push_back(0);

	std::list<int>::iterator i = l.begin();
	std::list<int>::iterator j = l.end();

	++i;
	--i;
	while (i != j)
	{
		std::cout << *i << std::endl;
		i++;
	}

	std::cout << "----------Copied stack-----------" << std::endl;

	MutantStack<int> mstack_copy;

	mstack_copy = mstack;

	mstack_copy.push(73);

	it = mstack_copy.begin();
	ite = mstack_copy.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	return 0;
}