#include "PmergeMe.hpp"

// -------------- Exceptions --------------

char const *PmergeMe::Error::what(void) const throw()
{
	return ("Error.\n");
};


// -------------- Constructors --------------

//default
PmergeMe::PmergeMe()
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
	int num = -1;

	size_t i = 1;
	while (argv[i] != NULL)
	{
		num = std::atoi(argv[i]);
		// std::cout << "num is: " << num << "\n";
		it = vector.begin();
		while (it != vector.end())
		{
			if (*it == num) //found duplicate
				throw Error();
			it++;
		}
		vector.push_back(num);
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
	time_t end;
	//save starting time
	time(&_timevec);
	std::cout << "timevec at start: " << _timevec << "\n";

	//init vector
	_initVec(argv);

	//sort
	//TODO

	//calc end time
	time(&end);
	_elapsedvec = end - _timevec;
	std::cout << "Sort Vector took: " << _elapsedvec << "\n";

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
	time_t end;
	//save starting time
	time(&_timelist);
	std::cout << "timelist at start: " << _timelist << "\n";

	//init vector
	_initList(argv);

	//sort
	//TODO

	//calc end time
	time(&end);
	_elapsedlist = end - _timelist;
	std::cout << "Sort List took: " << _elapsedlist << "\n";



}
