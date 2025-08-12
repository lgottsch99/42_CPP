#include "PmergeMe.hpp"

// -------------- Exceptions --------------

char const *PmergeMe::Error::what(void) const throw()
{
	return ("Error.\n");
};


// -------------- Constructors --------------

//default
PmergeMe::PmergeMe():
_elapsedvec(0), _elapsedlist(0), _numNumbers(0)
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
	std::cout << "Check only digits\n";
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
	std::cout << "Check input\n";
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

void PmergeMe::printBefore(char *argv[])
{
	std::cout << "Before: ";
	//at this point: argv is only valid pos int
	size_t i = 1;
	while (argv[i] != NULL)
	{
		std::cout << argv[i] << " ";
		i++;
	}
	_numNumbers = i - 1; //./skipped
	std::cout << "\n";
	std::cout << "Number of elems: " << _numNumbers <<"\n";
}

void PmergeMe::printAfter(void) //TODO set field width
{
	std::cout << "Time to process a range of " << _numNumbers << " with std::vector :  "
		<< std::setprecision(5) << _elapsedvec << " ms\n";
	std::cout << "Time to process a range of " << _numNumbers << " with std::list :  "
		<< std::setprecision(5) << _elapsedlist << " ms\n";

}

void PmergeMe::print_sequence(std::vector<int>& ref)
{//just print whole sequence of nums
	std::vector<int>::iterator it = ref.begin();

	while (it != ref.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << "\n";
}

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
	std::cout << "Vector initialized\n";
}

void PmergeMe::SortVector(char *argv[])
{
	(void)argv;
	//save starting time
	clock_t	 start = clock();

	//init vector
	_initVec(argv);

	//sort

	int rec_level = 1;
	_recFlag = 0;
	_VectorAlgo(rec_level);
	// for (int i = 0; i < 10000000; i++) //taking up time
	// {}

	//calc end time
	_elapsedvec = clock() - start; //clock ticks
	_elapsedvec = _elapsedvec * 1000.0 / CLOCKS_PER_SEC;// calc into milliseconds
	// std::cout << "Sort Vector took: " << _elapsedvec << "\n";

}

void PmergeMe::	_VectorAlgo(int level)
{// recursion orchestrator //rec: ft calling itself

	if (_recFlag == 1)
		std::cout << "going back\n";
	else
		std::cout << "going forward\n";

	print_sequence(_vec);
	//FORWARD STEPS here: sort pairs
	_sortPairs(level);

	print_sequence(_vec);


	//base case: no more pairs can be formed (pow(2, level) is size of single pair elem)
	if (_numNumbers - pow(2, level) < pow(2, level))
	{
		std::cout << "base case reached.\n";
		_recFlag = 1;
		return;
	}
	std::cout << "level: " << level << "\n";
	//call itself again = recursion
	_VectorAlgo(level + 1); 

	//do backwards steps here:
		//create main & pend and sort 
	std::cout << "DO step 2 3 here? level: " << level << "\n";
}

void PmergeMe::_sortPairs(int level)
{ // a/b index pos always stays same at same level
	//pos a's: at (i % pow(2, level) = 0 ) -> eg level 2: every 4.
	//pos b's: at (i % pow(2, level) = pow(2, level)/2 ) -> eg level 2:  2. 6 12 ..

	//
	
	std::vector<int> tmp_one; //placeholder for swapping
	std::vector<int> tmp_two; //placeholder for swapping
	std::vector<int> result; //placeholder for swapping

	int size_pair = pow(2, level); //size of  pair
	std::cout << "size pair is: " << size_pair << "\n";

	(void)level;

	//assign pairs/indexes

	//calc last index to read
	int last_index = _numNumbers;
	std::vector<int>::iterator it = _vec.end();
	while (it != _vec.begin() && (last_index % size_pair) != 0)
	{
		it--;
		last_index--;
	}
	std::cout << "last index to assign a/b is: " << last_index << "\n";
	

	// int first = 1;
	int i = 0;
	int current_pair = 1;

	while (i < last_index)
	{
		//copy into tmps
		//while first 1 -> cpy into tmp one
		if (current_pair <= size_pair/2)
			tmp_one.push_back(_vec[i]);
		else
			tmp_two.push_back(_vec[i]);
		
		//compare last of tmps
		if (current_pair == size_pair && i <= last_index) //at end of pair to compare
		{
			print_sequence(tmp_one);
			print_sequence(tmp_two);

			std::cout << "reached end of pair, comparing " << tmp_one[size_pair/2 - 1] << " against " << tmp_two[size_pair/2 - 1] << "\n";
			if (tmp_one[size_pair/2 - 1] > tmp_two[size_pair/2 - 1])
			{	//sort within pair
				//swap
				std::cout << "swapping...\n";

				std::vector<int>::iterator hi = tmp_two.begin();
				while (hi != tmp_two.end())
				{
					result.push_back(*hi);
					hi++;
				}
				tmp_two.clear();

				hi = tmp_one.begin();
				while (hi != tmp_one.end())
				{
					result.push_back(*hi);
					hi++;
				}
				tmp_one.clear();
			}
			else
			{
				std::vector<int>::iterator hi = tmp_one.begin();
				while (hi != tmp_one.end())
				{
					result.push_back(*hi);
					hi++;
				}
				tmp_one.clear();

				hi = tmp_two.begin();
				while (hi != tmp_two.end())
				{
					result.push_back(*hi);
					hi++;
				}
				tmp_two.clear();

			}
			current_pair = 0;
		}

		current_pair++;
		i++;
	}

	std::cout << "after loop it at: " << *it << std::endl;
	std::cout << "after loop i at: " << i << std::endl;

	//add rest to result

	while (last_index < _numNumbers)
	{
		std::cout << "pushing back rest\n";
		result.push_back(_vec[last_index]);
		last_index++;
	}

	std::cout << "RESULT SWAP LEVEL: " << level << "\n\t";
	print_sequence(result);

	_vec.swap(result);


}















void PmergeMe::_initList(char *argv[])
{
	int num;
	size_t i = 1;
	while (argv[i] != NULL)
	{
		num = std::atoi(argv[i]);
		_list.push_back(num);
		i++;
	}
	std::cout << "List initialized\n";
}

void PmergeMe::SortList(char *argv[])
{
	(void)argv;
	//save starting time
	clock_t	 start = clock();

	//init vector
	_initList(argv);

	//sort
	//TODO

	//calc end time
	_elapsedlist = clock() - start; //clock ticks
	_elapsedlist = _elapsedlist * 1000.0 / CLOCKS_PER_SEC;// calc into milliseconds

}
