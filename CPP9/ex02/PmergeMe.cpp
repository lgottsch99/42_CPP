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
	_numNumbers = i - 1; //./skipped
	std::cout << "\n";
	// std::cout << "Number of elems: " << _numNumbers <<"\n";
}

void PmergeMe::printAfter(void) //TODO set field width
{
	std::cout << "Time to process a range of " << _numNumbers << " with std::vector :  "
		<< std::setprecision(5) << _elapsedvec << " ms\n";
	std::cout << "Time to process a range of " << _numNumbers << " with std::list :  "
		<< std::setprecision(5) << _elapsedlist << " ms\n";

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

	//FORWARD STEPS: sort pairs

	//base case: no more pairs can be formed (pow(2, level) is size of single pair elem)
	if (_numNumbers - pow(2, level) < pow(2, level))
	{
		std::cout << "base case reached.\n";
		_recFlag = 1;
		return;
	}
	std::cout << "After base case, level: " << level << "\n";
	//call itself again
	_VectorAlgo(level + 1); 

	//do backwards steps here:
	std::cout << "ORRR maybe step 2 3 here? level: " << level << "\n";
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
