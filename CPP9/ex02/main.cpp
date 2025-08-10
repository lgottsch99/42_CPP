#include "PmergeMe.hpp"

// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
// https://link.springer.com/article/10.1007/s00224-020-09987-4
// https://42born2code.slack.com/archives/CN9RHKQHW/p1709984014933529?thread_ts=1709813537.388959&cid=CN9RHKQHW 
// 
//implement algo 2 times, with different containers each

//no map
//no stack/ deque

//using: 
//list
//unordered map? unordered set? vector?

/* Q's?????

how to manage the labelling in main chain? 
	numbers should keep their label until level is finished...


*/

int main(int argc, char *argv[])
{
	PmergeMe pm;
	(void)argv;
	//check input & print before : msg

	//sort with container 1
		//get current time before doing anything
		//init container
		//sort
		//get end time

	//sort with container 2 
		//get current time before doing anything
		//init container
		//sort
		//get end time
	
	//print result
	//calc time needed

	try
	{
		pm.CheckInput(argc, argv);
		pm.printBefore(argv);
		pm.SortVector(argv);
		// pm.SortList(argv);
		// pm.printAfter();

	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
		return 1;
	}
	return 0;

}

/*
algo	: recursive
	1. opening up recursion levels
		each level: divide into pairs and compare& sort by bigger
		END: whenno pair can be formed anymore

	2. resolving levels starting from the back:
		1 create main chain & pend (& non participaing)
			main chain: always b1 and a1 + all other a's
			pend: rest of b's

		2 sort pend into main chain
			binary insert with jacobsthal twist

			END; pend empty

		


*/

