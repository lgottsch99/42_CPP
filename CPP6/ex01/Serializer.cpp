
#include "Serializer.hpp"


//----------- Constructors ------------
//default
Serializer::Serializer(void)
{
	std::cout << "(Serializer) Default constructor\n";
}

//copy construct
Serializer::Serializer(const Serializer& other)
{
	(void)other;
	std::cout << "(Serializer) Copy constructor\n";
}

//copy assignment
Serializer &Serializer::operator=( const Serializer& other)
{
	(void)other;
	std::cout << "(Serializer) Copy assignment\n";
	if (this != &other)
	{
	}
	return (*this);
}

//destructor
Serializer::~Serializer()
{
	std::cout << "(Serializer) Destructor\n";
}

//----------- Methods ------------

/* uintptr_t is an unsigned integer type from <cstdint> that is specifically designed to hold a pointer's value safely.
It’s an integer large enough to store any pointer (on 64-bit machines, it's usually 64 bits wide).
*/
uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}


Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

