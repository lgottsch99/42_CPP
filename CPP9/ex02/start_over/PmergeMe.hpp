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


// //declaration for compiler
// template <typename Cont>
// struct NestedFor;

// // Case: Cont = std::vector<int> -> std::vector < std::vector<int> >
// template <>
// struct NestedFor< std::vector<int> > {
//     typedef std::vector<int> Inner; //inner is always gonna be int in list or vector!
//     typedef std::vector<Inner, std::allocator<Inner> > type;
// };

// // Case: Cont = std::list<int>
// template <>
// struct NestedFor< std::list<int> > {
//     typedef std::list<int> Inner;
//     typedef std::list<Inner, std::allocator<Inner> > type;
// };

// template <typename Cont>
// struct s_Pair {
//     typedef std::pair<Cont, Cont> Pair;
// };

template <typename Cont>
struct TraitsFor;

// Case: Cont = std::vector<int>
template <>
struct TraitsFor<std::vector<int> > {
    typedef std::vector<int> Inner;

    // container of Cont (like NestedFor did)
    typedef std::vector<Inner, std::allocator<Inner> > SimpleNested;

    // pair of Cont
    typedef std::pair< std::vector<int>, std::vector<int> > Pair;

    // container of pairs
    typedef std::vector<Pair, std::allocator<Pair> > PairContainer;
};

// Case: Cont = std::list<int>
template <>
struct TraitsFor<std::list<int> > {
    typedef std::list<int> Inner;

    typedef std::list<Inner, std::allocator<Inner> > SimpleNested;
    typedef std::pair<std::list<int>, std::list<int> > Pair;
    typedef std::list<Pair, std::allocator<Pair> > PairContainer;
};

class PmergeMe
{	
	private:
		void	_CheckOnlyDigits(char *argv[]);
		void	_CheckDuplicates(char *argv[]);
		void 	_initVec(char *argv[]);
		void 	_calcMaxComp(void);
		int		_getLastIndex(int size_elem, bool uneven);

		template <typename Cont>
		int _binary_search(int search_area, typename TraitsFor<Cont>::SimpleNested::iterator it_pend, typename TraitsFor<Cont>::SimpleNested& main_chain);
		//int _binary_search(int search_area, std::vector<std::vector<int> >::iterator it_pend, std::vector < std::vector<int> >& main_chain);
		

		//int _calc_search_area(typename std::vector < s_pair<Cont>::Pair > paired_sequence, int last_index, typename NestedFor<Cont>::type::iterator it_pend, typename NestedFor<Cont>::type main_chain);
		template <typename Cont>
		int _calc_search_area(typename TraitsFor<Cont>::PairContainer& paired_sequence, int last_index, typename TraitsFor<Cont>::SimpleNested::iterator it_pend, typename TraitsFor<Cont>::SimpleNested& main_chain);
		
		//template fj sort
		template <typename Cont>
		void _FJSort(Cont& c, int level);

		//template open up levels sort
		template <typename Cont>
		void _OpeningSort(Cont& c, int last_index, int size_elem, int size_pair, int level);

		//template binary insert
		template <typename Cont>
		void _BinaryInsert(Cont& c);

		//template gen j numbers
		template <typename Cont>
		Cont _genJNums(Cont c, int numNums);

		std::vector<int>	_vec;
		std::list<int>		_list;

		double				_elapsedvec; //save time it took to sort 
		double				_elapsedlist; //save time it took to sort 
		int 				_numNumbers; // number of numbers to sort
		int 				_maxComparisons;
		int 				_comps;
		bool				_UsingVector;


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


template <typename Cont>
int PmergeMe::_binary_search(int search_end, typename TraitsFor<Cont>::SimpleNested::iterator it_pend, typename TraitsFor<Cont>::SimpleNested& main_chain)
{
	int L = 0;
	int R = search_end;
	int T = (*it_pend).back(); //target value to insert
	int middle = 0;
	while (L <= R)
	{
		//one comparison per iteration
		_comps++;
		middle = L + (R - L) / 2;

		// std::cout << "main chain middle back() number: " << main_chain[middle].back() << "\n";
		if (main_chain[middle].back() < T)
			L = middle + 1;
		else if (main_chain[middle].back() > T)
			R = middle - 1;
	}
	middle = L; //if not exact match possible
	return (middle);
}


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
Cont PmergeMe::_genJNums(Cont c, int numNums)
{
	(void)c;
	Cont jnum;
	int sum = 3;

	int a = 1; //first j num
	int b = 3; //2. jnum
	jnum.push_back(3);

	while (sum < numNums)
	{
		int c = b + 2 * a;
		jnum.push_back(c);
		sum = sum + c;
		a = b;
		b = c;
	}
	if (DEBUG)
		std::cout << "number of jnums calced: " << jnum.size() << "\n";
	return(jnum);

}

template <typename Cont>
void PmergeMe::_OpeningSort(Cont& c, int last_index, int size_elem, int size_pair, int level)
{
	Cont sort_result;
	typename Cont::iterator it;

	//go thru c, read for size pair, split into two pair-vectors
	int i = 0;
	while (i < last_index)
	{
		Cont first;
		Cont second;

		int y = 0;
		while ((i + y) < last_index && y < size_elem)
		{
			first.push_back(c[i + y]);
			y++;
		}
		print_sequence(first);
		while ((i + y) < last_index && y < size_pair)
		{
			second.push_back(c[i + y]);
			y++;
		}
		print_sequence(second);
		//compare last number each, second = bigger! , swap if needed
		_comps++;
		if (first[size_elem - 1] > second[size_elem - 1]) //=comparison
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

	if (DEBUG)
	{
		std::cout << "RESULT SORT LEVEL " << level << " :\n\t";
		print_sequence(sort_result);
		std::cout << "no comps so far: " << _comps << "\n";
	}
	
	//swap c and result
	c.swap(sort_result);
}


template <typename Cont>
void PmergeMe::_FJSort(Cont& c, int level)
{	//recursive ft
	//use a vector of pairs! to keep track of sequence

	//typedef typename TraitsFor<Cont>::type SimpleNested; // alias for simple nested structure eg std::vector < std::vector<int> >

	int size_pair = pow(2, level);
	int size_elem = size_pair / 2; //size of single elem
	int num_elems = floor(_numNumbers / size_elem);
	bool uneven = num_elems % 2; // true if uneven num of elems
	int last_index = _getLastIndex(size_elem, uneven); //last even index! //get last index to assign to pairs

	if (DEBUG)
	{
		std::cout << "size elem is: " << size_elem << "\n";
		std::cout << "size pair is: " << size_pair << "\n";
		std::cout << "num elems is: " << num_elems << "\n";
		std::cout << "last index is: " << last_index << "\n";
	}

//open up levels: make pairs and compare, get bigger one
	_OpeningSort(c, last_index, size_elem, size_pair, level);

//recursion check
	//if base case: return 
	if (size_pair > _numNumbers)
	{
		if (DEBUG)
			std::cout << "\n -- base case reached -- \n\n";
		return;
	}
	//else recursion call
	if (DEBUG)
		std::cout << " -> Next Rec Level..\n";
	_FJSort(c, level + 1);

	if (DEBUG)
		std::cout << " # Level: " << level << "\n";


//close levels: 
	//parse into new structure (this is to keep pair-rel): 

	//typedef typename s_Pair<Cont>::Pair Pair;

	//std::vector < std::pair < std::vector<int>, std::vector<int> > > paired_sequence;
	//std::vector < Pair > paired_sequence;
	typename TraitsFor<Cont>::PairContainer paired_sequence;

	Cont uneven_elem;
	//go thru og sequence until last elem index
	int i = 0;
	while (i < last_index) // last index = last even elem index
	{
		Cont vec1;
		Cont vec2;

		int y = 0;
		while (y < size_elem)
		{//parse whole elem1 into vector
			vec1.push_back(c[i + y]);
			y++;
		}
		y = 0;
		while (y < size_elem && (i + y + size_elem) < (int)c.size())
		{//parse 2nd elem into vector 2
			vec2.push_back(c[i + size_elem + y]);
			y++;
		}
		//Make pair
		//add to paired seq
		if (DEBUG)
		{
			std::cout << "vec1: ";
			print_sequence(vec1);
			std::cout << "vec2: ";
			print_sequence(vec2);
		}
		paired_sequence.push_back( std::make_pair(vec1, vec2));

		i = i + size_pair;
	}
	if (uneven && i < (int)c.size()) //?remaining
	{
		int remaining = std::min(size_elem, (int)c.size() - i);
		for (int y = 0; y < remaining; y++)
			uneven_elem.push_back(c[i + y]);
		i += remaining; // increment by actual number copied
	}

	std::cout << "uneven: ";
	print_sequence(uneven_elem);
	
	Cont non_part;
	while (i < _numNumbers)
	{
		non_part.push_back(c[i]);
		i++;
	}
	std::cout << "non part: ";
	print_sequence(non_part);


// create main chain + pend
	// std::vector < std::vector<int> > main_chain; //b1, a1, rest of a's (pair 1, rest of pair.second()s)
	typename TraitsFor<Cont>::SimpleNested main_chain;
	// std::vector < std::vector<int> > pend; //rest of b's (rest of pair.first()s)
	typename TraitsFor<Cont>::SimpleNested pend;

	int paires_seq_size = paired_sequence.size();
	// std::cout << "paired seq size: " << paires_seq_size << "\n";

	int p = 0;//index pair
	//iterators to traverse outer+ inner vecs
	// TraitsFor<Cont>::PairContainer
	//for (typename std::vector < Pair >::iterator hi = paired_sequence.begin(); hi != paired_sequence.end(); hi++)
	for (typename TraitsFor<Cont>::PairContainer::iterator hi = paired_sequence.begin(); hi != paired_sequence.end(); hi++)
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

	if (DEBUG)
	{
		std::cout << "main chain: ";
		print_vector_of_vectors(main_chain);
		std::cout << "pend: ";
		print_vector_of_vectors(pend);
	}


// binary insert using j numbers: wichtig: nicht bezüge zwischen a-b paaren verlieren
	// gen j number seq.
	Cont jacob = _genJNums(c, _numNumbers); //ok
	typename Cont::iterator current_jacobsthal = jacob.begin();
	int previous_jacobsthal = 1;

	print_sequence(jacob);

	if (!pend.empty())
	{
		while (!pend.empty())
		{
			std::cout << "no comps so far: " << _comps << "\n\n";

			// group pend according to j number
			int num_elem_to_insert = *current_jacobsthal - previous_jacobsthal;
			std::cout << "insertion iteration. num of elems to insert: " << num_elem_to_insert << "\n";
			
			//CASE jnumber works (aka enough elems in pend)
			if (num_elem_to_insert <= (int)pend.size()) //jnumber works
			{
				//move iterator in pend to current elem
				// std::vector<std::vector<int> >::iterator it_pend = pend.begin();
				typename TraitsFor<Cont>::SimpleNested::iterator it_pend = pend.begin();//templated 
				for (int n = 0; n < num_elem_to_insert - 1; n++)
					it_pend++;
			
				std::cout << "traversed pend to elem: " << (*it_pend).back() << "\n";

				int iterations = 0;
				while (iterations < num_elem_to_insert)
				{
					std::cout << "Pend elem to insert: ";
					print_sequence(*it_pend);

					//search for partner elem (it_pend) in main, get index (aka search area)
						//std::vector < std::pair < std::vector<int>, std::vector<int> > > paired_sequence;
						//	std::vector < std::vector<int> > main_chain; //b1, a1, rest of a's (pair 1, rest of pair.second()s)
						//  std::vector < std::vector<int> > pend; //rest of b's (rest of pair.first()s)

					// calc search area in main (= look for upper bound a if any)
					int search_end = _calc_search_area<Cont>(paired_sequence, last_index, it_pend, main_chain);
					
		// binary insert (search area bleibt MEISTENS aber nicht immer the same!)
					//binary search main search area for index position to insert
				
					int middle = _binary_search<Cont>(search_end, it_pend, main_chain);

					
					std::cout << "inserting pend elem into main chain pos: " << middle << "\n";
					//insert (check if search area changed)
					typename TraitsFor<Cont>::SimpleNested::iterator it_main_chain = main_chain.begin();
					for (int i = 0; i < middle; i++)
						it_main_chain++;
					
					main_chain.insert(it_main_chain, *it_pend);
					
					//remove elem from pend
					typename TraitsFor<Cont>::SimpleNested::iterator one_before = it_pend;
					one_before--;

					pend.erase(it_pend);
					it_pend = one_before;
					iterations++;
				}

			
			previous_jacobsthal = *current_jacobsthal;
			current_jacobsthal++;
			}
			else //CASE: not enough elems in pend for jnumber
			{
				//just go to end of pend, insert starting from the back
				//move iterator in pend to current elem
				typename TraitsFor<Cont>::SimpleNested::iterator it_pend = pend.end(); //end() returns past the end!
				it_pend--;

				std::cout << "Not enough elems for jnumber left! inserting from back of pend now\n";
				
				num_elem_to_insert = pend.size();
				std::cout << "Number of pend elems to insert: " << num_elem_to_insert << "\n";
				//
				int iterations = 0;
				while (iterations < num_elem_to_insert)
				{
					//search for partner elem (it_pend) in main, get index (aka search area)
						//std::vector < std::pair < std::vector<int>, std::vector<int> > > paired_sequence;
						//	std::vector < std::vector<int> > main_chain; //b1, a1, rest of a's (pair 1, rest of pair.second()s)
						//  std::vector < std::vector<int> > pend; //rest of b's (rest of pair.first()s)

					std::cout <<"Pend elem to insert: ";
					print_sequence(*it_pend);

					int search_end = _calc_search_area<Cont>(paired_sequence, last_index, it_pend, main_chain);
					std::cout << "search end is: " << search_end << "\n";

					std::cout << "bianry inserting..\n";
					//binary search main search area for index position to insert
					int middle = _binary_search<Cont>(search_end, it_pend, main_chain);
					std::cout << "inserting pend elem into main chain pos: " << middle << "\n";

					//insert (check if search area changed)
					typename TraitsFor<Cont>::SimpleNested::iterator it_main_chain = main_chain.begin();
					for (int i = 0; i < middle; i++)
						it_main_chain++;
					
					main_chain.insert(it_main_chain, *it_pend);
					
					//remove elem from pend
					typename TraitsFor<Cont>::SimpleNested::iterator one_before = it_pend;
					one_before--;

					pend.erase(it_pend);
					it_pend = one_before;
					iterations++;
				}
			}
		}
	}

	Cont insert_result;
//create new single vector with result 
	for (typename TraitsFor<Cont>::SimpleNested::iterator hey = main_chain.begin(); hey != main_chain.end(); hey++)
	{
		const Cont& inner_vector = *hey;
		for (typename Cont::const_iterator inner = inner_vector.begin(); inner != inner_vector.end(); inner++)
		{
			insert_result.push_back(*inner);
		}
	}
	if (!non_part.empty()) //adding non participating back to main chain
	{
		unsigned long a = 0;
		while (a < non_part.size())
		{
			insert_result.push_back(non_part[a]);
			a++;
		}
	}
	if (DEBUG)
	{
		std::cout << "insert result: ";
		print_sequence(insert_result);
	}

	c.swap(insert_result);
}


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



//int PmergeMe::_calc_search_area(std::vector < std::pair < std::vector<int>, std::vector<int> > > paired_sequence, int last_index, std::vector<std::vector<int> >::iterator it_pend, std::vector < std::vector<int> > main_chain)
//int PmergeMe::_calc_search_area(typename std::vector < typename s_Pair<Cont>::Pair >& paired_sequence, int last_index, typename TraitsFor<Cont>::SimpleNested::iterator it_pend, typename TraitsFor<Cont>::SimpleNested& main_chain)
template <typename Cont>
int PmergeMe::_calc_search_area(typename TraitsFor<Cont>::PairContainer& paired_sequence, int last_index, typename TraitsFor<Cont>::SimpleNested::iterator it_pend, typename TraitsFor<Cont>::SimpleNested& main_chain)
{
	//typedef typename NestedFor<Cont>::type SimpleNested; // alias for simple nested structure eg std::vector < std::vector<int> >
	//typedef typename s_Pair<Cont>::Pair Pair;
	
	bool found = false;
	int search_end = 0; //end of search area in main

	// std::pair < std::vector<int>, std::vector<int> > partner_pair;
	//typedef typename s_Pair<Cont>::Pair Pair;
	typename TraitsFor<Cont>::Pair partner_pair;

	//std::vector < std::pair < std::vector<int>, std::vector<int> > >::iterator it_paired_outer = paired_sequence.begin();
	typename TraitsFor<Cont>::PairContainer::iterator it_paired_outer = paired_sequence.begin();

	for (int index = 0; index < last_index; index++)
	{
		if ((*it_paired_outer).first == *it_pend)
		{
			partner_pair = (*it_paired_outer);
			std::cout << "found partner elem!\n";
			print_sequence(partner_pair.second);
			found = true;
			break;
		}
		it_paired_outer++;
	}
	if (found)
	{
		//look for partner elem position in main_chain
		while (search_end < (int)main_chain.size() && main_chain[search_end] != partner_pair.second)
			search_end++;

		std::cout << "partner in main chain at pos: " << search_end << "\n";
		//no need to compare partner elem tho so -1 index
		search_end--;
	}
	else
	{
		std::cout <<"no partner found in paired seq\n";
		search_end = (int)main_chain.size();
		search_end--; //index at 0
	}
	return(search_end);
}


#endif