#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
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
#define CHECK_COMPS 1

/*
Specialization allows type-dependent logic:
TraitsFor<Cont> can be different depending on Cont.
You write your algorithms using typename TraitsFor<Cont>::SimpleNested, Pair, etc., and the compiler picks the correct types automatically.

Code reuse:
You can write one set of functions templated on Cont and they will work for vector<int> or deque<int> without rewriting the algorithm.

Compile-time resolution:
All type aliases are resolved at compile time, so there is no runtime overhead.
*/

template <typename Cont> //primary template(placeholder), but cannot be instantiated w/o specialization
struct TraitsFor;

//specialization
// Case: Cont = std::vector<int>
template <>  //<- tells compiler this is full specialization, but only applies to std::vector<int>
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
struct TraitsFor<std::deque<int> > {
    typedef std::deque<int> Inner;

    typedef std::deque<Inner, std::allocator<Inner> > SimpleNested;
    typedef std::pair<std::deque<int>, std::deque<int> > Pair;
    typedef std::deque<Pair, std::allocator<Pair> > PairContainer;
};


class PmergeMe
{	
	private:
		void	_CheckOnlyDigits(char *argv[]);
		void	_CheckDuplicates(char *argv[]);
		void 	_initVec(char *argv[]);
		void 	_initDeq(char *argv[]);
		void 	_calcMaxComp(void);
		int		_getLastIndex(int size_elem, bool uneven);
		bool	_result_equal(void);
		bool	_is_sorted(void);

		template <typename Cont>
		void _initCont(char *argv[], Cont& c);

		template <typename Cont>
		int _binary_search(int search_area, typename TraitsFor<Cont>::SimpleNested::iterator it_pend, typename TraitsFor<Cont>::SimpleNested& main_chain);		

		template <typename Cont> //used by vector
		int _calc_search_area(typename TraitsFor<Cont>::PairContainer& paired_sequence, int last_index, typename TraitsFor<Cont>::SimpleNested::iterator it_pend, typename TraitsFor<Cont>::SimpleNested& main_chain);
		int _calc_search_area_deque(std::deque < std::pair < std::deque<int>, std::deque<int> > > &paired_sequence, int last_index, std::deque<std::deque<int> >::iterator it_pend, std::deque<std::deque<int> > &main_chain);

		void _FJSort_Vector(int level);
		void _FJSort_Deque(int level);

		template <typename Cont> //used by vector
		void _OpeningSort(Cont& c, int last_index, int size_elem, int size_pair, int level);
		void _OpeningSort_Deque(std::deque<int>& c, int last_index, int size_elem, int size_pair, int level);

		template <typename Cont>
		void _BinaryInsert(Cont& c);

		template <typename Cont>
		Cont _genJNums(Cont c, int numNums);

		template <typename T>
		void print_sequence(T& ref);

		template <typename Cont>
		void printSimpleNested(typename TraitsFor<Cont>::SimpleNested object);

		std::vector<int>	_vec;
		std::vector<int>	_SortedVec;
		int					_CompsVec;
		std::deque<int>		_deq;
		std::deque<int>		_SortedDeq;
		int					_CompsDeq;

		double				_elapsedvec; //save time it took to sort 
		double				_elapseddeq; //save time it took to sort 
		int 				_numNumbers; // number of numbers to sort
		int 				_maxComparisons;
		int 				_comps;
	
	public:
		PmergeMe(void);//default
		PmergeMe(const PmergeMe& other); //copy construct
		PmergeMe &operator=( const PmergeMe& other); //copy assignment
		~PmergeMe(); //destructor


		void CheckInput(int argc, char *argv[]);
		void printBefore(char *argv[]);
		void printAfter(void);

		void SortVector(char *argv[]);
		void SortDeque(char *argv[]);

		class Error : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};
		class ResultError : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};
};

template <typename Cont>
void PmergeMe::_initCont(char *argv[], Cont& c)
{
	int num;
	size_t i = 1;
	while (argv[i] != NULL)
	{
		num = std::atoi(argv[i]);
		c.push_back(num);
		i++;
	}
	_numNumbers = i - 1; //./skipped

	if (DEBUG)
	{
		std::cout << "Cont initialized\n";
		std::cout << "Number of numbers: " << _numNumbers <<"\n";
	}
}


template <typename Cont>
int PmergeMe::_binary_search(int search_end, typename TraitsFor<Cont>::SimpleNested::iterator it_pend, typename TraitsFor<Cont>::SimpleNested& main_chain)
{
	//it_pend -> points to elem in pend we want to insert

    //std::cout << "in binary search\n";
    typedef typename TraitsFor<Cont>::SimpleNested::iterator Iterator;

    if (it_pend->empty()) 
		return 0; // safety (calling .back() on empty container crashes)

    int T = it_pend->back();// T target value = number to compare 
    int index = 0;

    Iterator left = main_chain.begin();
    Iterator right = main_chain.begin();
    int steps = std::min(search_end + 1, (int)main_chain.size()); // Without the +1, the iterator right would point just before search_end, excluding the right element in the search area
    for (int i = 0; i < steps; ++i) 
		right++;  // advance safely for dque and vector // need to advance manually to be safe for deque 

    while (left != right)
    {
        int dist = std::distance(left, right); //1 Compute distance between left and right.
        
		Iterator middle = left; //2 Move middle to midpoint manually, safe for deque
        for (int i = 0; i < dist / 2; ++i) 
			middle++; 

		//one comparison per iteration
        _comps++;
        if (middle->back() < T) // 3 If middle elem is less than target, move left after middle
        {
            Iterator tmp = middle; //used to not invalidate for following else
            tmp++;
            left = tmp;
        }
        else
            right = middle;
    }

    index = std::distance(main_chain.begin(), left); //converts left iteratir to int index 
   // std::cout << "finished binary search\n";
    return index;
}

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
		if (DEBUG)
			print_sequence(first);
		while ((i + y) < last_index && y < size_pair)
		{
			second.push_back(c[i + y]);
			y++;
		}
		if (DEBUG)
			print_sequence(second);
		
		//compare last number each, second = bigger! , swap if needed
		_comps++;
		if (first.back() > second.back())
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
	while (i < _numNumbers && i < (int)c.size())
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



template <typename Cont>
int PmergeMe::_calc_search_area(
    typename TraitsFor<Cont>::PairContainer &paired_sequence,
    int last_index,
    typename TraitsFor<Cont>::SimpleNested::iterator it_pend,
    typename TraitsFor<Cont>::SimpleNested &main_chain)
{
    // std::cout << "in calc search area\n";

    bool found = false;
    int search_end = 0;

    typename TraitsFor<Cont>::Pair partner_pair;
    typename TraitsFor<Cont>::PairContainer::iterator it_paired_outer = paired_sequence.begin();

	//look for partner to it_pend 
    int index = 0;
    while (it_paired_outer != paired_sequence.end() && index < last_index) //it past end()->undefined + CRASH! Thats why 
    {
        if ((*it_paired_outer).first == *it_pend)
        {
            partner_pair = *it_paired_outer;
            found = true;
            break;
        }
        ++it_paired_outer;
        ++index;
    }

    if (found)
    {
		//get pos of partner in main chain
        typename TraitsFor<Cont>::SimpleNested::iterator it = main_chain.begin();
        search_end = 0;
        while (it != main_chain.end() && *it != partner_pair.second)
        {
            ++it;
            ++search_end;
        }
        if (DEBUG)
            std::cout << "partner in main chain at pos: " << search_end << "\n";

        //no need to compare partner elem itself tho so -1 index
        if (search_end > 0)
            search_end--;
    }
    else //no partner elem found, compare with entire main chain
    {
        if (DEBUG)
            std::cout << "no partner found in paired seq\n";
        search_end = (int)main_chain.size();
        if (search_end > 0) //index at 0 -> compare with entire main chain
        search_end--; 
    }

    // std::cout << "finished calc search area\n";
    return search_end;
}


template <typename Cont>
void PmergeMe::printSimpleNested(typename TraitsFor<Cont>::SimpleNested object)
{
    // Iterate over outer vector
    for (typename TraitsFor<Cont>::SimpleNested::const_iterator it = object.begin(); it != object.end(); ++it)
	{
        // it is iterator to std::vector<int>
        // dereference it to get inner vector
        const Cont& inner_object = *it;

        // Iterate over the inner vector
        for (typename Cont::const_iterator inner_it = inner_object.begin(); inner_it != inner_object.end(); ++inner_it) {
            std::cout << *inner_it << " ";
        }
    }
	std::cout << std::endl; 
}


#endif