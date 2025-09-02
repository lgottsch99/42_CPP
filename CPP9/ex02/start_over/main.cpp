#include "PmergeMe.hpp"

// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
// https://link.springer.com/article/10.1007/s00224-020-09987-4
// https://42born2code.slack.com/archives/CN9RHKQHW/p1709984014933529?thread_ts=1709813537.388959&cid=CN9RHKQHW 


int main(int argc, char *argv[])
{
	PmergeMe pm;
	
	try
	{
		pm.CheckInput(argc, argv); //throws error if bigger int max, char or duplicate found
		pm.printBefore(argv);
		pm.SortVector(argv);
		pm.SortDeque(argv);
		pm.printAfter();

	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
		return 1;
	}
	return 0;
}

