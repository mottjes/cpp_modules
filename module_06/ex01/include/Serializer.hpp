#pragma once

#include <iostream>
#include <stdint.h>

typedef struct s_data
{
	int		value1;
	int		value2;
}		Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &rhs);
	~Serializer();
	Serializer& operator=(const Serializer &rhs);

public:
	static uintptr_t serialize(Data* ptr);
	static Data*	 deserialize(uintptr_t raw);
	
};