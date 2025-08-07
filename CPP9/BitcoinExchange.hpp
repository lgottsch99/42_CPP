

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
		bool ValidateLine(); // date | value -> single | found?

		void ConvertAndPrint(); //looks up data, calcs amount

		void OpenInputFile(std::string &filename);
		void ProcessFile(std::string &filename);


};

#endif