
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>


// https://en.cppreference.com/w/cpp/container/stack.html 

template <typename T, typename Container=std::deque<T> >
class MutantStack: public std::stack<T, Container> //inheriting from stack
{

	public:
		MutantStack(void);//default
		MutantStack(const MutantStack& other); //copy construct
		MutantStack &operator=( const MutantStack& other); //copy assignment
		~MutantStack(); //destructor

		//iterators
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator rev_iterator;
		typedef typename Container::const_reverse_iterator const_rev_iterator;
		
		//iterator fts
		iterator begin();
		iterator end();
		const_iterator cbegin();
		const_iterator cend();
		rev_iterator rbegin();
		rev_iterator rend();
		const_rev_iterator crbegin();
		const_rev_iterator crend();


		//members
		//push pop etc (get from deque)

		//push
		void	push(T elem); //deque push_back

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
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& other)
{
	(void)other;
	std::cout << "(MutantStack) Copy constructor\n";
}

//copy assignment
template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=( const MutantStack<T, Container>& other)
{
	(void)other;
	std::cout << "(MutantStack) Copy assignment\n";
	if (this != &other)
	{
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
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}


template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return (this->c.end()); //c is container in std::stack
}


template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cbegin()
{
	return (this->c.cbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cend()
{
	return (this->c.cend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::rev_iterator MutantStack<T, Container>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::rev_iterator MutantStack<T, Container>::rend()
{
	return (this->c.rend());
}


template <typename T, typename Container>
typename MutantStack<T, Container>::const_rev_iterator MutantStack<T, Container>::crbegin()
{
	return (this->c.crbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_rev_iterator MutantStack<T, Container>::crend()
{
	return (this->c.crend());
}


#endif