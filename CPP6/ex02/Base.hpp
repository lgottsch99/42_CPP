#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{	
	public:
		virtual ~Base(); //destructor

		static Base*	generate(void);
		static void		identify(Base* p); //ptr
		static void		identify(Base& p); //ref


};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif