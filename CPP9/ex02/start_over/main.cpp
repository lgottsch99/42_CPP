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

START OVER:

	-algo = clean template


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


Original:       [8, 3, 5, 1, 7]

Opening:
- Make pairs -> mainChain=[3,1], pend=[8,5], odd=7
- Recurse on mainChain=[3,1]
   - Pair again -> mainChain=[1], pend=[3]
   - Recurse on [1] -> base case

Closing (stack unwinds):
- Insert pend=[3] into mainChain=[1] -> [1,3]
- Insert pend=[8,5] into mainChain=[1,3] -> [1,3,5,8]
- Insert odd=7 -> [1,3,5,7,8]



#include <vector>
#include <algorithm> // for std::lower_bound

// --- Ford-Johnson (FJ) sort ---
template <typename Cont>
void FJSort(Cont &c)
{
    // --- Opening stage: base case ---
    if (c.size() <= 1)
        return; // already sorted

    // --- Opening stage: make pairs ---
    Cont mainChain; // will become the sorted backbone
    Cont pend;      // elements to insert later

    typename Cont::iterator it = c.begin();
    while (it != c.end())
    {
        typename Cont::iterator next = it;
        ++next;
        if (next != c.end())
        {
            // Pair elements: smaller goes to mainChain, larger to pend
            if (*it < *next)
            {
                mainChain.push_back(*it);
                pend.push_back(*next);
            }
            else
            {
                mainChain.push_back(*next);
                pend.push_back(*it);
            }
            it = ++next;
        }
        else
        {
            // Odd element, will insert later
            pend.push_back(*it);
            ++it;
        }
    }

    // --- Opening stage: recursive call on mainChain ---
    FJSort(mainChain);

    // --- Closing stage: insert pend elements into sorted mainChain ---
    for (typename Cont::iterator p = pend.begin(); p != pend.end(); ++p)
    {
        typename Cont::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), *p);
        mainChain.insert(pos, *p);
    }

    // --- Closing stage: copy back to original container ---
    c.clear();
    for (typename Cont::iterator m = mainChain.begin(); m != mainChain.end(); ++m)
        c.push_back(*m);
}

*/

