
#include "Serializer.hpp"


int main(void)
{
	Data* ptr = new Data;

	ptr->i = 42;
	ptr->lol = "hellololol";

	//test 
	std::cout << ptr->i << "\n";
	std::cout << ptr->lol << "\n\n";

	//serialize
	uintptr_t serialized_ptr = Serializer::serialize(ptr);
	std::cout << "after serialize(): " << serialized_ptr << "\n";

	//deserialize
	Data* deserialized_ptr = Serializer::deserialize(serialized_ptr);
	std::cout << "after DEserialize():	" << deserialized_ptr << "\n";
	std::cout << "ORIGINAL ptr address:	" << ptr << "\n";


	delete ptr;
}