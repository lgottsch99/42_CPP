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

	//TODO: count numnumbers here!!!
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
	std::cout << "Number of numbers: " << _numNumbers <<"\n";
}

void PmergeMe::SortVector(char *argv[])
{
	(void)argv;
	//save starting time
	clock_t	 start = clock();
	int level = 1;

	//init vector
	_initVec(argv);

	_comps = 0;
	_calcMaxComp();
	//sort
	_FJSort(_vec, level);

	std::cout << "max no of comps allowed: " << _maxComparisons << "\n";
	std::cout << "no of comps needed: " << _comps << "\n";

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



void PmergeMe::print_vector_of_vectors(const std::vector<std::vector<int> >& main_chain) {
    // Iterate over the outer vector
    for (std::vector<std::vector<int> >::const_iterator it = main_chain.begin(); it != main_chain.end(); ++it) {
        // 'it' is an iterator to a std::vector<int>
        // Dereference 'it' to get the current inner vector
        const std::vector<int>& inner_vector = *it;

        // Iterate over the inner vector
        for (std::vector<int>::const_iterator inner_it = inner_vector.begin(); inner_it != inner_vector.end(); ++inner_it) {
            // Dereference 'inner_it' to get the current integer
            std::cout << *inner_it << " ";
        }
        
    }
	std::cout << std::endl; 
}



std::vector<int> PmergeMe::_genJNums(int numNums)
{//how many are needed? sum of all needs to be >= _numnumbers
	std::vector<int> jnum;
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

	// std::cout << "sum is: " << sum << "\n";
	std::cout << "number of jnums calced: " << jnum.size() << "\n";
	return(jnum);

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