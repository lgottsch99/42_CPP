

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>      // std::stringstream
#include <utility>
#include <cstdlib>
#include <iomanip> 
#include <stdexcept> // for std::runtime_error
#include <exception>

class BitcoinExchange
{	
	private:
		
		bool					_ReadCsv();

	public:
		std::map<std::string, float>	CsvData; //make private

		BitcoinExchange(void);//default
		BitcoinExchange(const BitcoinExchange& other); //copy construct
		BitcoinExchange &operator=( const BitcoinExchange& other); //copy assignment
		~BitcoinExchange(); //destructor


		bool ValidateDate(); //yyyy-mm-dd ? valid numbers? 
		bool ValidateAmount(); // positove int or float btw 0-1000?
		void ValidateLine(std::string& line); // date | value -> single | found?

		void ConvertAndPrint(); //looks up data, calcs amount

		std::ifstream& OpenInputFile(std::string &filename);
		void ProcessFile(std::ifstream& infile, std::string &filename);

		class InvalidInputLine : public std::exception 
		{
			public:
				const char * what(std::string &line) const throw();
		};

};

#endif