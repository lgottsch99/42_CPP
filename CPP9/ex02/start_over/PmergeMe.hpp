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

		int _getLastIndex(int size_elem, bool uneven);

		//template fj sort
		template <typename Cont>
		void _FJSort(Cont& c, int level);

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


 // a/b index pos always stays same at same level
	//pos a's: at (i % pow(2, level) = 0 ) -> eg level 2: every 4.
	//pos b's: at (i % pow(2, level) = pow(2, level)/2 ) -> eg level 2:  2. 6 12 ..


*/

template <typename Cont>
void PmergeMe::_FJSort(Cont& c, int level)
{	//recursive ft
	//use a vector of pairs! to keep track of sequence
	

	int size_pair = pow(2, level);
	int size_elem = size_pair / 2; //size of single elem
	int num_elems = floor(_numNumbers / size_elem);
	bool uneven = num_elems % 2; // true if uneven num of elems

	std::cout << "size elem is: " << size_elem << "\n";
	std::cout << "size pair is: " << size_pair << "\n";
	std::cout << "num elems is: " << num_elems << "\n";


//open up levels: make pairs and compare, get bigger one
	// std::vector < <std::vector<int> > elem_seq; //store single elems grouped (ungerade muss möglich sein)
	// std::vector <int> non_part; //store leftover who cant form element
	
//read c into paired seq
		//get last index to assign to pairs
	int last_index = _getLastIndex(size_elem, uneven);
	// std::cout << "last index is: " << last_index << "\n";

	std::vector <int> sort_result;
	std::vector<int>::iterator it;

	int i = 0;
	while (i < last_index)
	{//go thru c, read for size pair, split into two pair-vectors

		std::vector <int> first;
		std::vector <int> second;

		int y = 0;
		while ((i+y) < last_index && y < size_elem)
		{
			first.push_back(c[i + y]);
			y++;
		}
		print_sequence(first);

		while ((i+y) < last_index && y < size_pair)
		{
			second.push_back(c[i + y]);
			y++;
		}
		print_sequence(second);

		//compare last number each, second = bigger! , swap if needed
		if (first[size_elem - 1] > second[size_elem - 1])
		{
			it = second.begin();
			while (it != second.end())
			{	
				sort_result.push_back(*it);
				it++;
			}
			it = first.begin();
			while (it != first.end())
			{	
				sort_result.push_back(*it);
				it++;
			}
		}
		else 
		{
			it = first.begin();
			while (it != first.end())
			{	
				sort_result.push_back(*it);
				it++;
			}
			it = second.begin();
			while (it != second.end())
			{	
				sort_result.push_back(*it);
				it++;
			}
		}

		i = i + size_pair;
	}
	while (i < _numNumbers)
	{
		sort_result.push_back(c[i]);
		i++;
	}
	std::cout << "RESULT SORT LEVEL " << level << " :\n\t";
	print_sequence(sort_result);
	//swap c and result
	c.swap(sort_result);

	//if base case: return 
	if (_numNumbers - pow(2, level) < pow(2, level))
	{
		std::cout << "\n -- base case reached -- \n\n";
		return;
	}
	//else recursion call
	std::cout << "Next Rec Level..\n";
	_FJSort(c, level + 1);


	//close levels: 
	//restore into vector < pair < vec, vec>> to not loose relationship btw pairs 
	// create main chain + pend
	// binary insert using j numbers
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