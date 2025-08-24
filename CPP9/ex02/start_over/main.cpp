#include "PmergeMe.hpp"

// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
// https://link.springer.com/article/10.1007/s00224-020-09987-4
// https://42born2code.slack.com/archives/CN9RHKQHW/p1709984014933529?thread_ts=1709813537.388959&cid=CN9RHKQHW 
// 
// implement algo 2 times, with different containers each

//no map
//no stack/ deque

//using: 
//list
//unordered map? unordered set? vector?

/* Q's?????


*/
/* TODO

dry

template form?

list test

ADD COMPARISON COUNTER AND CHECK

shrinking of search area?
	comps in opening up OK
	comps in closing??

	
*/



int main(int argc, char *argv[])
{
	PmergeMe pm;
	(void)argv;
	
	try
	{
		pm.CheckInput(argc, argv);
		if (DEBUG)
			pm.printBefore(argv);
		pm.SortVector(argv);
		// pm.SortList(argv);
		//pm.printAfter();

	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
		return 1;
	}
	return 0;

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

*/

