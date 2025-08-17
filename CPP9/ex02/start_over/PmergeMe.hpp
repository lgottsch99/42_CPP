#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <unistd.h>
#include <cmath>
#include <limits>


#define DEBUG 1


class PmergeMe
{	
	private:
		void	_CheckOnlyDigits(char *argv[]);
		void	_CheckDuplicates(char *argv[]);
		void 	_initVec(char *argv[]);

		//template fj sort
		template <typename Cont>
		void _FJSort(Cont& c);

		//template binary insert
		template <typename Cont>
		void _BinaryInsert(Cont& c);

		//template gen j numbers
		template <typename Cont>
		void _genJNums(Cont& c);


		
		std::vector<int>	_vec;
		std::list<int>		_list;

		double				_elapsedvec; //save time it took to sort 
		double				_elapsedlist; //save time it took to sort 
		int 				_numNumbers; // number of numbers to sort


	public:
		PmergeMe(void);//default
		PmergeMe(const PmergeMe& other); //copy construct
		PmergeMe &operator=( const PmergeMe& other); //copy assignment
		~PmergeMe(); //destructor


		void CheckInput(int argc, char *argv[]);
		void printBefore(char *argv[]);
		void printAfter(void);

		void SortVector(char *argv[]);

		template <typename T>
		void print_sequence(T& ref);

		class Error : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};

};

/*
“Opening” the recursion (going down):
	When we “open” recursion (i.e., the call stack grows):
	Check base case → return if reached.
	Pair elements → (smaller, larger)
	Separate into mainChain and pend
	Recurse on mainChain
-> At this stage, nothing is inserted yet. We are just preparing the sorted backbone.

“Closing” the recursion (unwinding the stack)
	When recursion returns (i.e., stack unwinds):
		mainChain is now sorted.
		Insert pend elements one by one into mainChain using binary search.
		Insert the odd element, if there was one.
		Copy back to the original container if needed.
-> The important part: all insertions happen while closing recursion, because only now do we know the mainChain is sorted.


Original:       [8, 3, 5, 1, 7]

Opening:
- Make pairs -> mainChain=[3,1], pend=[8,5], odd=7
- Recurse on mainChain=[3,1]
   - Pair again -> mainChain=[1], pend=[3]
   - Recurse on [1] -> base case

Closing (stack unwinds):
- Insert pend=[3] into mainChain=[1] -> [1,3]
- Insert pend=[8,5] into mainChain=[1,3] -> [1,3,5,8]
- Insert odd=7 -> [1,3,5,7,8]

*/

template <typename Cont>
void PmergeMe::_FJSort(Cont& c)
{
	//return if base case reached 
	if (c.size() <= 1)
	{
		std::cout << " - base case reached! - \n";
		return;
	}

	//make pairs
	//build main chain + pend (smaller go directly into main chain, bigger into pend)
	Cont main_chain;
	Cont pend;

	typename Cont::iterator it = c.begin();
	while (it != c.end())
	{
		typename Cont::iterator next = it;
		++next;		//it at pos 1, next at 2
		if (next != c.end())
		{
			//smaller to main chain, bigger to pend
			if (*it < *next)
			{
				main_chain.push_back(*it);
				pend.push_back(*next);
			}
			else
			{
				pend.push_back(*it);
				main_chain.push_back(*next);
			}
			next++;
			it = next; //jump to next 2 
		}
		else //odd elem, push to pend for now and insert later
		{
			pend.push_back(*it);
			it++;
		}
		
	}
	std::cout << "mainchain: ";
	print_sequence(main_chain);
	std::cout << "pend: ";
	print_sequence(pend);

	//rec call
	std::cout << "Next recursion call..\n";
	_FJSort(main_chain);

	//closing: binary insert using j numbers

	//closing: copy into OG containter 


	//     // --- Closing stage: insert pend elements into sorted mainChain ---
    // for (typename Cont::iterator p = pend.begin(); p != pend.end(); ++p)
    // {
    //     typename Cont::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), *p);
    //     mainChain.insert(pos, *p);
    // }

    // // --- Closing stage: copy back to original container ---
    // c.clear();
    // for (typename Cont::iterator m = mainChain.begin(); m != mainChain.end(); ++m)
    //     c.push_back(*m);

}

//template binary insert
template <typename Cont>
void _BinaryInsert(Cont& c);

//template gen j numbers
template <typename Cont>
void _genJNums(Cont& c);


template <typename T>
void PmergeMe::print_sequence(T& ref)
{
	typename T::iterator it = ref.begin();

	while (it != ref.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << "\n";
}


#endif