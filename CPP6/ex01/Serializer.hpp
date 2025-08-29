#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <string>
#include <iostream>
#include <stdint.h> //uintptr

class Serializer
{	
	private:
		Serializer(void);//default
		Serializer(const Serializer& other); //copy construct
		Serializer &operator=( const Serializer& other); //copy assignment
		~Serializer(); //destructor

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif