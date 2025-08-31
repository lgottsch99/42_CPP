#include "PmergeMe.hpp"

// -------------- Exceptions --------------

char const *PmergeMe::Error::what(void) const throw()
{
	return ("Error.\n");
};

char const *PmergeMe::ResultError::what(void) const throw()
{
	return ("Sortnig Result: Error. Vector and deque result not the same!\n");
};



// -------------- Constructors --------------

//default
PmergeMe::PmergeMe():
_elapsedvec(0), _elapseddeq(0), _numNumbers(0)
{
	std::cout << "(PmergeMe) Default constructor\n";
}

//copy construct
PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
	std::cout << "(PmergeMe) Copy constructor\n";
	//_vec = other.getVec;
}

//copy assignment
PmergeMe &PmergeMe::operator=( const PmergeMe& other)
{
		(void)other;
	std::cout << "(PmergeMe) Copy assignment operator\n";
	if (this != &other)
	{
		//_vec = other.getVec;
	}
	return (*this);
}

//destructor
PmergeMe::~PmergeMe()
{
	std::cout << "(PmergeMe) Destructor\n";
}

// -------------- Members --------------

void PmergeMe::_CheckDuplicates(char *argv[])
{
	//we know: argv = only positive ints
	std::vector<int> 			vector;
	std::vector<int>::iterator 	it = vector.begin();
	long num = -1;

	size_t i = 1;
	while (argv[i] != NULL)
	{
		num = std::atol(argv[i]);
		//check out of range for int
		if (num > std::numeric_limits<int>::max())
			throw Error();

		//check duplicates
		it = vector.begin();
		while (it != vector.end())
		{
			if (*it == num) //found duplicate
				throw Error();
			it++;
		}
		vector.push_back(static_cast<int>(num));
		i++;
	}
}

void PmergeMe::_CheckOnlyDigits(char *argv[])
{
	//std::cout << "Check only digits\n";
	size_t i = 1; //skip ./bla
	while (argv[i] != NULL)
	{
		size_t y = 0;
		while (argv[i][y] != '\0')
		{
			if (!isdigit(argv[i][y]))
				throw Error();
			y++;
		}
		i++;
	}
}

void PmergeMe::CheckInput(int argc, char *argv[])
{
	//std::cout << "Check input\n";
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe <number sequence to sort>\n";
		throw PmergeMe::Error();
	}

	//go thru each argv, check digits only (also no -!)
	_CheckOnlyDigits(argv);

	//check duplicates
	_CheckDuplicates(argv);
}

//TODO TEMPLATE
void PmergeMe::_initVec(char *argv[])
{
	int num;
	size_t i = 1;
	while (argv[i] != NULL)
	{
		num = std::atoi(argv[i]);
		_vec.push_back(num);
		i++;
	}
	_numNumbers = i - 1; //./skipped

	if (DEBUG)
	{
		std::cout << "Vector initialized\n";
		std::cout << "Number of numbers: " << _numNumbers <<"\n";
	}
}
//TODO TEMPLATE
void PmergeMe::_initDeq(char *argv[])
{
	int num;
	size_t i = 1;
	while (argv[i] != NULL)
	{
		num = std::atoi(argv[i]);
		_deq.push_back(num);
		i++;
	}
	_numNumbers = i - 1; //./skipped

	if (DEBUG)
	{
		std::cout << "Deque initialized\n";
		std::cout << "Number of numbers: " << _numNumbers <<"\n";
	}
}


void PmergeMe::printBefore(char *argv[]) //can 
{
	std::cout << "Before: ";
	//at this point: argv is only valid pos int
	size_t i = 1;
	while (argv[i] != NULL)
	{
		std::cout << argv[i] << " ";
		i++;
	}
	std::cout << "\n";	
}

void PmergeMe::SortVector(char *argv[])
{
	(void)argv;
	//save starting time
	clock_t	 start = clock();
	int level = 1;

	//_initVec(argv);
	_initCont(argv, _vec);

	_comps = 0;
	_calcMaxComp();

	_FJSort_Vector(level);

	_SortedVec = _vec;
	_CompsVec = _comps;

	//calc end time
	_elapsedvec = clock() - start; //clock ticks
	_elapsedvec = _elapsedvec * 1000.0 / CLOCKS_PER_SEC;// calc into milliseconds
	// std::cout << "Sort Vector took: " << _elapsedvec << "\n";
}

void PmergeMe::_FJSort_Vector(int level)
{
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
	_OpeningSort(_vec, last_index, size_elem, size_pair, level);

//recursion check
	//if base case: return 
	if (size_pair > _numNumbers)
	{
		if (DEBUG)
			std::cout << "\n -- base case reached -- \n\n";
		if (CHECK_COMPS)
			std::cout << "VEC Opening Sort comps: " << _comps << "\n";

		return;
	}
	//else recursion call
	if (DEBUG)
		std::cout << " -> Next Rec Level..\n";
	_FJSort_Vector(level + 1);

	if (DEBUG)
		std::cout << " # Level: " << level << "\n";


//close levels: 
//parse into new structure (this is to keep pair-rel): 
	std::vector < std::pair < std::vector<int>, std::vector<int> > > paired_sequence;
	std::vector <int> uneven_elem;

	// std::vector <int>::iterator it = _vec.begin();
	// std::vector <int>::iterator end_it = _vec.end();

	int i = 0;
	while (i < last_index) // last index = last even elem index
	{
		std::vector <int> vec1;
		std::vector <int> vec2;

		int y = 0;
		while (y < size_elem)
		{//parse whole elem1 into vector
			vec1.push_back(_vec[i + y]);
			y++;
		}
		y = 0;
		while (y < size_elem && (i + y + size_elem) < (int)_vec.size())
		{//parse 2nd elem into vector 2
			vec2.push_back(_vec[i + size_elem + y]);
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
	if (uneven && i < (int)_vec.size()) //?remaining
	{
		int remaining = std::min(size_elem, (int)_vec.size() - i);
		for (int y = 0; y < remaining; y++)
			uneven_elem.push_back(_vec[i + y]);
		i += remaining; // increment by actual number copied
	}

	if (DEBUG)
	{
		std::cout << "uneven: ";
		print_sequence(uneven_elem);
	}
	
	std::vector <int> non_part;
	while (i < _numNumbers && i < (int)_vec.size())
	{
		non_part.push_back(_vec[i]);
		i++;
	}
	if (DEBUG)
	{
		std::cout << "non part: ";
		print_sequence(non_part);
	}

// create main chain + pend
	std::vector< std::vector<int> > main_chain;
	std::vector< std::vector<int> > pend;

	std::vector < std::pair < std::vector<int>, std::vector<int> > >::iterator hi = paired_sequence.begin();

	// Handle the first element pair (b1, a1)
	if (hi != paired_sequence.end()) 
	{
		main_chain.push_back(hi->first);  // b1
		main_chain.push_back(hi->second); // a1
		hi++; // Move to next elem
	}
	// Handle the rest of the pairs
	for (; hi != paired_sequence.end(); hi++) 
	{
		main_chain.push_back(hi->second); // a
		pend.push_back(hi->first);        // b
	}
	// Add the uneven element if it exists
	if (!uneven_elem.empty()) 
		pend.push_back(uneven_elem);

	if (DEBUG) 
	{
		std::cout << "main chain: ";
		printSimpleNested<std::vector<int> >(main_chain);
		std::cout << "pend: ";
		printSimpleNested<std::vector<int> >(pend);
	}
	
// binary insert using j numbers: wichtig: nicht bezüge zwischen a-b paaren verlieren

	// gen j number seq.
	std::vector<int> jacob = _genJNums(_vec, _numNumbers); //ok
	std::vector<int>::iterator current_jacobsthal = jacob.begin();
	int previous_jacobsthal = 1;

	if (DEBUG)
		print_sequence(jacob);

	if (!pend.empty())
	{
		while (!pend.empty())
		{
			// group pend according to j number
			int num_elem_to_insert = *current_jacobsthal - previous_jacobsthal;
			if (DEBUG)
			{
				std::cout << "no comps so far: " << _comps << "\n\n";
				std::cout << "insertion iteration. num of elems to insert: " << num_elem_to_insert << "\n";
			}

		//CASE jnumber works (aka enough elems in pend)
			if (num_elem_to_insert <= (int)pend.size()) //jnumber works
			{
				//move iterator in pend to current elem
				std::vector<std::vector<int> >::iterator it_pend = pend.begin();
				for (int n = 0; n < num_elem_to_insert - 1; n++)
					it_pend++;
			
				//if (it_pend != pend.end())
				if (DEBUG)
				{
					std::cout <<"jnumber insertion..\n";
					std::cout << "traversed pend to elem: " << (*it_pend).back() << "\n";
				}

				int iterations = 0;
				while (iterations < num_elem_to_insert)
				{
					if (DEBUG)
					{
						std::cout << "Pend elem to insert: ";
						print_sequence(*it_pend);
					}

					//search for partner elem (it_pend) in main, get index (aka search area)
					// calc search area in main (= look for upper bound a if any)
					int search_end = _calc_search_area<std::vector<int> >(paired_sequence, last_index, it_pend, main_chain);
					
		// binary insert (search area bleibt MEISTENS aber nicht immer the same!)
					//binary search main search area for index position to insert
				
					int middle = _binary_search<std::vector<int> >(search_end, it_pend, main_chain);
					if (DEBUG)
						std::cout << "inserting pend elem into main chain pos: " << middle << "\n";
				
					//insert (check if search area changed)
					std::vector<std::vector<int> >::iterator it_main_chain = main_chain.begin();
					for (int i = 0; i < middle; i++)
						it_main_chain++;
					
					main_chain.insert(it_main_chain, *it_pend);
					
					//remove elem from pend
					std::vector<std::vector<int> >::iterator one_before = it_pend;
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
				std::vector<std::vector<int> >::iterator it_pend = pend.end(); //end() returns past the end!
				it_pend--;

				num_elem_to_insert = pend.size();

				if (DEBUG)
				{
					std::cout << "Not enough elems for jnumber left! inserting from back of pend now\n";
					std::cout << "Number of pend elems to insert: " << num_elem_to_insert << "\n";
				}

				int iterations = 0;
				while (iterations < num_elem_to_insert)
				{
					if (DEBUG)
					{
						std::cout <<"Pend elem to insert: ";
						print_sequence(*it_pend);
					}

					int search_end = _calc_search_area<std::vector<int> >(paired_sequence, last_index, it_pend, main_chain);

					//binary search main search area for index position to insert
					int middle = _binary_search<std::vector<int> >(search_end, it_pend, main_chain);

					if (DEBUG)
						std::cout << "inserting pend elem into main chain pos: " << middle << "\n";

					//insert (check if search area changed)
					std::vector<std::vector<int> >::iterator it_main_chain = main_chain.begin();
					for (int i = 0; i < middle; i++)
						it_main_chain++;

					main_chain.insert(it_main_chain, *it_pend);
					
					//remove elem from pend
					std::vector<std::vector<int> >::iterator one_before = it_pend;
					one_before--;

					pend.erase(it_pend);
					it_pend = one_before;
					iterations++;
				}
			}
		}
	}

	std::vector<int> insert_result;
    
    // Use iterators to copy elements from main_chain to insert_result
    for (std::vector<std::vector<int> >::iterator it_main = main_chain.begin(); it_main != main_chain.end(); ++it_main)
    {
        // Use an iterator to copy the inner container
        for (std::vector<int>::const_iterator it_inner = it_main->begin(); it_inner != it_main->end(); ++it_inner)
            insert_result.push_back(*it_inner);
    }

    // Use iterators to copy the non-participating elements
    if (!non_part.empty())
    {
        for (std::vector<int>::const_iterator it = non_part.begin(); it != non_part.end(); ++it)
            insert_result.push_back(*it);
    }

    if (DEBUG)
    {
        std::cout << "insert result: ";
        print_sequence(insert_result);
    }
    _vec.swap(insert_result);
}

void PmergeMe::SortDeque(char *argv[])
{
	(void)argv;
	//save starting time
	clock_t	 start = clock();
	int level = 1;

	_initDeq(argv);

	_comps = 0;
	_calcMaxComp();
	//sort
	_FJSort_Deque(level);

	_SortedDeq = _deq;
	_CompsDeq = _comps;

	//calc end time
	_elapseddeq = clock() - start; //clock ticks
	_elapseddeq = _elapseddeq * 1000.0 / CLOCKS_PER_SEC;// calc into milliseconds
	// std::cout << "Sort Vector took: " << _elapseddeq << "\n";
}

void PmergeMe::_FJSort_Deque(int level)
{
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
	//CRASHING
	//_OpeningSort(_deq, last_index, size_elem, size_pair, level);
	_OpeningSort_Deque(_deq, last_index, size_elem, size_pair, level);
//recursion check
	//if base case: return 
	if (size_pair > _numNumbers)
	{
		if (DEBUG)
			std::cout << "\n -- base case reached -- \n\n";
		if (CHECK_COMPS)
			std::cout << "DEQ Opening Sort comps: " << _comps << "\n";

		return;
	}
	//else recursion call
	if (DEBUG)
		std::cout << " -> Next Rec Level..\n";
	_FJSort_Deque(level + 1);

	if (DEBUG)
		std::cout << " # Level: " << level << "\n";



//close levels: 
//parse into new structure (this is to keep pair-rel): 
	std::deque < std::pair < std::deque<int>, std::deque<int> > > paired_sequence;
	std::deque <int> uneven_elem;

	int i = 0;
	while (i < last_index) // last index = last even elem index
	{
		std::deque <int> vec1;
		std::deque <int> vec2;

		std::deque <int>::iterator it = _deq.begin();
		for (int k = 0; k < i && it != _deq.end(); k++)
			it++;

		int y = 0;
		while (y < size_elem && it != _deq.end())
		{//parse whole elem1 into vector
			vec1.push_back(*it);
			y++;
			it++;
		}
		y = 0;
		//while (y < size_elem && (i + y + size_elem) < (int)_deq.size())
		while(y < size_elem && it != _deq.end())
		{//parse 2nd elem int_maxComparisonso vector 2
			vec2.push_back(*it);
			y++;
			it++;
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
	if (uneven && i < (int)_deq.size()) //?remaining
	{
		int remaining = std::min(size_elem, (int)_deq.size() - i);

		std::deque<int>::iterator it = _deq.begin();
		for (int k = 0; k < i && it != _deq.end(); k++) //advance to i
			it++;

		for (int y = 0; y < remaining && it != _deq.end(); y++, it++)
			uneven_elem.push_back(*it);
		i = i + remaining; // increment by actual number copied
	}

	if (DEBUG)
	{
		std::cout << "uneven: ";
		print_sequence(uneven_elem);
	}
	
	std::deque <int> non_part;
	std::deque <int>::iterator it = _deq.begin();
	for (int k = 0; k < i && it != _deq.end(); k++) //advance to i
		it++;

	while (i < _numNumbers && it != _deq.end())//i < (int)_deq.size())
	{
		non_part.push_back(*it);
		i++;
		it++;
	}
	if (DEBUG)
	{
		std::cout << "non part: ";
		print_sequence(non_part);
	}

// create main chain + pend
	std::deque< std::deque<int> > main_chain;
	std::deque< std::deque<int> > pend;

	std::deque < std::pair < std::deque<int>, std::deque<int> > >::iterator hi = paired_sequence.begin();

	// Handle the first element pair (b1, a1)
	if (hi != paired_sequence.end()) 
	{
		main_chain.push_back(hi->first);  // b1
		main_chain.push_back(hi->second); // a1
		hi++; // Move to next elem
	}
	// Handle the rest of the pairs
	for (; hi != paired_sequence.end(); hi++) 
	{
		main_chain.push_back(hi->second); // a
		pend.push_back(hi->first);        // b
	}
	// Add the uneven element if it exists
	if (!uneven_elem.empty()) 
		pend.push_back(uneven_elem);

	if (DEBUG) 
	{
		std::cout << "main chain: ";
		printSimpleNested<std::deque<int> >(main_chain);
		std::cout << "pend: ";
		printSimpleNested<std::deque<int> >(pend);
	}
	
// binary insert using j numbers: wichtig: nicht bezüge zwischen a-b paaren verlieren

	// gen j number seq.
	std::deque<int> jacob = _genJNums<std::deque<int> >(_deq, _numNumbers); //ok
	std::deque<int>::iterator current_jacobsthal = jacob.begin();
	int previous_jacobsthal = 1;

	if (DEBUG)
		print_sequence(jacob);

	if (!pend.empty())
	{
		while (!pend.empty())
		{
			// group pend according to j number
			int num_elem_to_insert = *current_jacobsthal - previous_jacobsthal;
			if (DEBUG)
			{
				std::cout << "no comps so far: " << _comps << "\n\n";
				std::cout << "insertion iteration. num of elems to insert: " << num_elem_to_insert << "\n";
			}

		//CASE jnumber works (aka enough elems in pend)
			if (num_elem_to_insert <= (int)pend.size()) //jnumber works
			{			
					
             // We'll use an index for backward iteration
                int current_idx = num_elem_to_insert - 1;
                
                if (DEBUG)
                {
                    std::cout <<"jnumber insertion..\n";
                    std::cout << "traversed pend to elem: " << pend[current_idx].back() << "\n";
                }

                int iterations = 0;
                // Loop while there are elements to insert and we are within bounds
                while (iterations < num_elem_to_insert && current_idx >= 0 && !pend.empty())
                {
                    if (DEBUG)
                    {
                        std::cout << "Pend elem to insert: ";
                        print_sequence(pend[current_idx]);
                    }

                    // search for partner elem (it_pend) in main, get index (aka search area)
                    // _calc_search_area_deque will need to be refactored to take an index, or you can create a temporary iterator
                    // A safe way to get a temporary iterator is:
                    std::deque<std::deque<int> >::iterator it_pend_temp = pend.begin() + current_idx;
                    int search_end = _calc_search_area_deque(paired_sequence, last_index, it_pend_temp, main_chain);
                
                    // binary insert
                    int middle = _binary_search<std::deque<int> >(search_end, it_pend_temp, main_chain);

                    if (DEBUG)
                        std::cout << "inserting pend elem into main chain pos: " << middle << "\n";

                    // insert
                    std::deque<std::deque<int> >::iterator it_main_chain = main_chain.begin();
                    if (middle > 0)
                        it_main_chain += middle;
                    
                    main_chain.insert(it_main_chain, pend[current_idx]);
                    
                    // Erase the element at the current index.
                    // This is the key. The erase() call is what invalidates iterators.
                    // By using an index, we avoid the invalidation issue for the loop control.
                    it_pend_temp = pend.begin() + current_idx;
                    pend.erase(it_pend_temp);
                    
                    // The "move back" logic is now just decrementing the index.
                    // The element that was at index `current_idx - 1` is now at `current_idx - 1`.
                    current_idx--; 
                    
                    iterations++;
				}
			
			previous_jacobsthal = *current_jacobsthal;
			current_jacobsthal++;
			}
			else //CASE: not enough elems in pend for jnumber
			{
				if (pend.empty())
                    return;

                num_elem_to_insert = pend.size();
                int current_idx = num_elem_to_insert - 1; // start from the end
                
                if (DEBUG)
                {
                    std::cout << "Not enough elems for jnumber left! inserting from back of pend now\n";
                    std::cout << "Number of pend elems to insert: " << num_elem_to_insert << "\n";
                }

                int iterations = 0;
                while (iterations < num_elem_to_insert && current_idx >= 0 && !pend.empty())
                {
                    if (DEBUG)
                    {
                        std::cout <<"Pend elem to insert: ";
                        print_sequence(pend[current_idx]);
                    }
                    
                    // Create a temporary iterator for the functions that require it
                    std::deque<std::deque<int> >::iterator it_pend_temp = pend.begin() + current_idx;

                    int search_end = _calc_search_area_deque(paired_sequence, last_index, it_pend_temp, main_chain);
                    int middle = _binary_search<std::deque<int> >(search_end, it_pend_temp, main_chain);

                    if (DEBUG)
                        std::cout << "inserting pend elem into main chain pos: " << middle << "\n";

                    std::deque<std::deque<int> >::iterator it_main_chain = main_chain.begin();
                    if (middle > 0)
                        it_main_chain += middle;
                    
                    main_chain.insert(it_main_chain, pend[current_idx]);
                    
                    // Erase the element and update the index
                    it_pend_temp = pend.begin() + current_idx;
                    pend.erase(it_pend_temp); 

                    // Move "back" one element
                    current_idx--;

                    iterations++;
				}
			}
		}
	}

	std::deque<int> insert_result;
    
    // Use iterators to copy elements from main_chain to insert_result
    for (std::deque<std::deque<int> >::iterator it_main = main_chain.begin(); it_main != main_chain.end(); ++it_main)
    {
        // Use an iterator to copy the inner container
        for (std::deque<int>::const_iterator it_inner = it_main->begin(); it_inner != it_main->end(); ++it_inner)
            insert_result.push_back(*it_inner);
    }

    // Use iterators to copy the non-participating elements
    if (!non_part.empty())
    {
        for (std::deque<int>::const_iterator it = non_part.begin(); it != non_part.end(); ++it)
            insert_result.push_back(*it);
    }

    if (DEBUG)
    {
        std::cout << "insert result: ";
        print_sequence(insert_result);
    }
    _deq.swap(insert_result);

}

void PmergeMe::_OpeningSort_Deque(std::deque<int>& c, int last_index, int size_elem, int size_pair, int level)
{
	// std::cout << "in open sort deque\n";
	std::deque<int> sort_result;

	if (last_index > (int)c.size()) //last index seems to be too big for deque??
    	last_index = c.size();

	//go thru c, read for size pair, split into two pair-vectors
	int i = 0;
	while (i < last_index)
	{
		// std::cout << "loop\n";
		std::deque<int> first;
		std::deque<int> second;

		std::deque<int>::iterator it = c.begin();
		// move to starting index i
		for (int k = 0; k < i && it != c.end(); ++k)
    		++it;

		int y = 0;
		while (it != c.end() && (i + y) < last_index && y < size_elem)
		{
			first.push_back(*it);
			y++;
			it++;
		}

		if (DEBUG)
			print_sequence(first);
		while ((i + y) < last_index && y < size_pair && it != c.end())
		{
			second.push_back(*it);
			y++;
			it++;
		}
		if (DEBUG)
			print_sequence(second);
		
		//compare last number each, second = bigger! , swap if needed
		_comps++;
		//if (first[size_elem - 1] > second[size_elem - 1]) //=comparison
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

	std::deque<int>::iterator it = c.begin();
	// move to starting index i
	for (int k = 0; k < i && it != c.end(); ++k)
    	++it;

	while (i < _numNumbers && i < (int)c.size() && it != c.end())
	{
		sort_result.push_back(*it);
		i++;
		it++;
	}

	if (DEBUG)
	{
		std::cout << "RESULT SORT LEVEL " << level << " :\n\t";
		print_sequence(sort_result);
		std::cout << "no comps so far: " << _comps << "\n";
	}
	
	//swap c and result
	c.swap(sort_result);
	// std::cout << "finished open sort\n";
}


int PmergeMe::_calc_search_area_deque(
    std::deque < std::pair < std::deque<int>, std::deque<int> > > &paired_sequence,
    int last_index,
    std::deque<std::deque<int> >::iterator it_pend,
    std::deque<std::deque<int> > &main_chain)
{
    // std::cout << "in calc search area\n";

    bool found = false;
    int search_end = 0;

    std::pair < std::deque<int>, std::deque<int> > partner_pair;
    std::deque < std::pair < std::deque<int>, std::deque<int> > >::iterator it_paired_outer = paired_sequence.begin();

    // secure last_index to container size in case last index too big for cont
    int max_index = (int)paired_sequence.size();
    if (last_index > max_index)
        last_index = max_index;

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
        std::deque<std::deque<int> >::iterator it = main_chain.begin();
        search_end = 0;
        while (it != main_chain.end() && *it != partner_pair.second)
        {
            ++it;
            ++search_end;
        }
        if (DEBUG)
            std::cout << "partner in main chain at pos: " << search_end << "\n";

        //no need to compare partner elem tho so -1 index
        if (search_end > 0)
            search_end--;
    }
    else
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

bool PmergeMe::_result_equal(void)
{
	std::vector<int>::iterator it_vec = _vec.begin();
	std::deque<int>::iterator it_deq = _deq.begin();

	for (int i = 0; i < _numNumbers; i++)
	{
		if (*it_vec != *it_deq)
			return false;
		it_vec++;
		it_deq++;
	}
	return true;
}

bool PmergeMe::_is_sorted(void)
{
	std::vector<int>::iterator it_vec = _vec.begin();
	int prev = *it_vec;

	for (int i = 1; i < _numNumbers; i++) //start at 2nd num
	{
		if (*it_vec < prev)
			return false;
		prev = *it_vec;
		it_vec++;
	}
	return true;
}


void PmergeMe::printAfter(void) //TODO set field width
{
//check if both vector and deque sorted and the same!
	//if ok:
	if (!_result_equal() || !_is_sorted())
		throw ResultError();

	// std::cout << "Vec Afte_maxComparisonsr:  ";
	// print_sequence(_SortedVec);

	std::cout << "After:  ";
	print_sequence(_SortedDeq);

	std::cout << "Time to process a range of " << _numNumbers << " with std::vector :  "
		<< std::setprecision(5) << _elapsedvec << " ms\n";
	std::cout << "Time to process a range of " << _numNumbers << " with std::deque :  "
		<< std::setprecision(5) << _elapseddeq << " ms\n";

	if (CHECK_COMPS)
	{
		std::cout << "Number of max allowed comps: " << _maxComparisons << "\n";
		std::cout << "No Comps Vector: " << _CompsVec << "\n";
		std::cout << "No Comps Deque:  " << _CompsDeq << "\n";
	}

}


int PmergeMe::_getLastIndex(int size_elem, bool uneven)
{
	int last_index;

	if (!uneven)
		last_index = _numNumbers;
	else
		last_index = _numNumbers - size_elem;

	while (last_index % size_elem != 0)
		last_index--;

	return (last_index);
}


void PmergeMe::_calcMaxComp(void)
{
    int sum = 0;
    for (int k = 1; k <= _numNumbers; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    _maxComparisons = sum;
}
