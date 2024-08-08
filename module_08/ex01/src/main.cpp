#include "../include/Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "----------------------" << std::endl;

	try
	{
		std::vector<int> randomNumbers(10000);
		std::srand(time(NULL));
		for (size_t i = 0; i < randomNumbers.size(); i++)
			randomNumbers[i] = std::rand();

		Span s(10000);

		s.addNumbers(randomNumbers.begin(), randomNumbers.end());
		std::cout << "shortest Span: " << s.shortestSpan() << std::endl;
		std::cout << "longes Span: " << s.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}