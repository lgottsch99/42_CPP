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
	_numNumbers = i - 1; //./skipped
	std::cout << "\n";
	std::cout << "Number of elems: " << _numNumbers <<"\n";
}

void PmergeMe::SortVector(char *argv[])
{
	(void)argv;
	//save starting time
	clock_t	 start = clock();

	//init vector
	_initVec(argv);

	//sort
	_FJSort(_vec);

	//calc end time
	_elapsedvec = clock() - start; //clock ticks
	_elapsedvec = _elapsedvec * 1000.0 / CLOCKS_PER_SEC;// calc into milliseconds
	// std::cout << "Sort Vector took: " << _elapsedvec << "\n";
}


void PmergeMe::printAfter(void) //TODO set field width
{
	std::cout << "Time to process a range of " << _numNumbers << " with std::vector :  "
		<< std::setprecision(5) << _elapsedvec << " ms\n";
	std::cout << "Time to process a range of " << _numNumbers << " with std::list :  "
		<< std::setprecision(5) << _elapsedlist << " ms\n";

}
