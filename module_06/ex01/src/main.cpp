#include "../include/Serializer.hpp"

int	main(void)
{
	Data data;

	data.value1 = -5;
	data.value2 = 42;

	std::cout << "Data value1: " << data.value1 << std::endl;
	std::cout << "Data value2: " << data.value2 << std::endl;

	uintptr_t	serialized = Serializer::serialize(&data);
	Data 		*deserialized = Serializer::deserialize(serialized);

	std::cout << "deserialized value1: " << deserialized->value1 << std::endl;
	std::cout << "deserialized value2: " << deserialized->value2 << std::endl;

	return 0;
}