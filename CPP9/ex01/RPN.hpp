#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <list>
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <iomanip>

class RPN
{	
	private:
		int 	_is_op;
		std::stack<double, std::list<double> > _stack;

		int _ParseAndCalc(std::string &input);
		void _addition(void);
		void _substraction(void);
		void _multiplication(void);
		void _division(void);
		bool IsOperator(char c);

	public:
		RPN(void);//default
		RPN(const RPN& other); //copy construct
		RPN &operator=( const RPN& other); //copy assignment
		~RPN(); //destructor

		int Process(std::string &input);
};

#endif