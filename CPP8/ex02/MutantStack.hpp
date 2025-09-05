
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>


// https://en.cppreference.com/w/cpp/container/stack.html 

template <typename T, typename Container=std::deque<T> > //container param like std::stack defualt is deque but any is fine
class MutantStack: public std::stack<T, Container> //inheriting from stack 
{
	//container c inherited from std::stack

	public:
		MutantStack(void);//default
		MutantStack(const MutantStack& other); //copy construct
		MutantStack &operator=( const MutantStack& other); //copy assignment
		~MutantStack(); //destructor

		//iterator alias: to make code more reusable/ versatile w different container types
		typedef typename Container::iterator iterator;

		//iterator fts
		iterator begin(void);
		iterator end(void);

		//iterator overloads? ++ -- ... ->not needed, inherited from stack


		//members -> inherited? 
		//push pop etc (get from deque)

		//push

		//pop//deque pop_back

		//empty //deque e,pty
		//size //deque size
		//top //?


};


//----------- Constructors ------------
//default
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void)
{
	std::cout << "(MutantStack) Default constructor\n";
}

//copy construct
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& other):
std::stack<T, Container>(other) //better: letting base class handle the copying
{
	std::cout << "(MutantStack) Copy constructor\n";
	this->c = other.c;
}

//copy assignment
template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=( const MutantStack<T, Container>& other)
{
	(void)other;
	std::cout << "(MutantStack) Copy assignment\n";
	if (this != &other)
	{
		this->c = other.c;
	}
	return (*this);
}

//destructor
template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
	std::cout << "(MutantStack) Destructor\n";
}

//----------- Iterators ------------

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());
}


template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void)
{
	return (this->c.end()); //c is container in std::stack
}


#endif