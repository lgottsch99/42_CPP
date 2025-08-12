#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <unistd.h>
#include <cmath>

class PmergeMe
{	
	private:

		void	_CheckOnlyDigits(char *argv[]);
		void	_CheckDuplicates(char *argv[]);
		void 	_initVec(char *argv[]);//could be template
		void	_initList(char *argv[]);//could be template
		void	_VectorAlgo(int level);

		std::vector<int>	_vec;
		double				_elapsedvec; //save time it took to sort 
		std::list<int>		_list;
		double				_elapsedlist; //save time it took to sort 
		int 				_numNumbers; // number of numbers to sort
		int 				_recFlag;


	public:
		PmergeMe(void);//default
		PmergeMe(const PmergeMe& other); //copy construct
		PmergeMe &operator=( const PmergeMe& other); //copy assignment
		~PmergeMe(); //destructor

		void CheckInput(int argc, char *argv[]);
		void printBefore(char *argv[]);
		void SortVector(char *argv[]);
		void SortList(char *argv[]);
		void printAfter(void);

		class Error : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};

};

#endif