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

		//template gen j numbers //TODO template
		std::vector<int> _genJNums(int numNums);


		
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

		void print_vector_of_vectors(const std::vector<std::vector<int> >& main_chain);



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
	int last_index = _getLastIndex(size_elem, uneven); //last even index!
	std::cout << "last index is: " << last_index << "\n";

	Cont sort_result;
	typename Cont::iterator it;

	int i = 0;
	while (i < last_index)
	{//go thru c, read for size pair, split into two pair-vectors

		Cont first;
		Cont second;

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
	// if (_numNumbers - pow(2, level) < size_elem)
	{
		std::cout << "\n -- base case reached -- \n\n";
		return;
	}
	//else recursion call
	std::cout << " -> Next Rec Level..\n";
	_FJSort(c, level + 1);

	std::cout << " # Level: " << level << "\n";

	//Todo change to template style Cont
//close levels: 
	//parse into new structure (this is to keep pair-rel): 
		//option1: restore into vector < pair < vec, vec>> to not loose relationship btw pairs (what if uneven??)
		//option2: new struct ( vector int, index int, flag b/a)

	std::vector < std::pair < std::vector<int>, std::vector<int> > > paired_sequence;
	std::vector <int> uneven_elem;
	//go thru og seq until last elem index
	i = 0;
	while (i < last_index) // last index = last even elem index
	{
		std::vector<int> vec1;
		std::vector<int> vec2;

		int y = 0;
		while (y < size_elem)
		{//parse whole elem1 into vector
			vec1.push_back(_vec[i + y]);
			y++;
		}
		while (y < size_pair)
		{//parse 2nd elem into vector 2
			vec2.push_back(_vec[i + y]);
			y++;
		}
		//Make pair
		//add to paired seq
		std::cout << "vec1: ";
		print_sequence(vec1);
		std::cout << "vec2: ";
		print_sequence(vec2);
		paired_sequence.push_back( std::make_pair(vec1, vec2));

		i = i + size_pair;
	}
	if (uneven)
	{
		int y = 0;
		while (y < size_elem)
		{
			uneven_elem.push_back(_vec[i+y]);
			y++;
			i++;
		}
	}
	std::cout << "uneven: ";
	print_sequence(uneven_elem);
	
	std::vector <int> non_part;
	while (i < _numNumbers)
	{
		non_part.push_back(_vec[i]);
		i++;
	}
	std::cout << "non part: ";
	print_sequence(non_part);


// create main chain + pend
	std::vector < std::vector<int> > main_chain; //b1, a1, rest of a's (pair 1, rest of pair.second()s)
	std::vector < std::vector<int> > pend; //rest of b's (rest of pair.first()s)

	int paires_seq_size = paired_sequence.size();
	// std::cout << "paired seq size: " << paires_seq_size << "\n";


	int p = 0;//index pair
	//iterators to traverse outer+ inner vecs
	for (std::vector < std::pair < std::vector<int>, std::vector<int> > >::iterator hi = paired_sequence.begin(); hi != paired_sequence.end(); hi++)
	{
		if (p == 0 && paires_seq_size >= 1)
		{
			main_chain.push_back(paired_sequence[p].first); //b1
			main_chain.push_back(paired_sequence[p].second); // ai
		}
		else if (p < paires_seq_size)
		{
			main_chain.push_back(paired_sequence[p].second); // a 
			pend.push_back(paired_sequence[p].first); // b
		}
		p++;
	}
	if (uneven)
	{
		pend.push_back(uneven_elem);
	}

	std::cout << "main chain: ";
	print_vector_of_vectors(main_chain);
	std::cout << "pend: ";
	print_vector_of_vectors(pend);

	if (!pend.empty())
	{
	// binary insert using j numbers: wichtig: nicht bezüge zwischen a-b paaren verlieren
		// gen j number seq.
		std::vector<int> jacob = _genJNums(_numNumbers);
		print_sequence(jacob);
		// group pend according to j number
		// calc search area in main (= look for upper bound a if any)
		// binary insert (search area bleibt MEISTENS aber nicht immer the same!)


	}

	std::vector<int> insert_result;
	//create new single vector with result 
	for (std::vector < std::vector<int> >::iterator hey = main_chain.begin(); hey != main_chain.end(); hey++)
	{
		const std::vector<int>& inner_vector = *hey;
		for (std::vector<int>::const_iterator inner = inner_vector.begin(); inner != inner_vector.end(); inner++)
		{
			insert_result.push_back(*inner);
		}
	}
	if (!non_part.empty())
	{
		unsigned long a = 0;
		while (a < non_part.size())
		{
			insert_result.push_back(non_part[a]);
			a++;
		}
	}
	std::cout << "insert result: ";
	print_sequence(insert_result);

	// c.swap(insert_result);



}

//template binary insert
template <typename Cont>
void _BinaryInsert(Cont& c);



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