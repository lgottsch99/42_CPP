

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

class BitcoinExchange
{	
	private:
		std::map<date, value>	_CsvData;
		bool					_ReadCsv();

	public:
		BitcoinExchange(void);//default
		BitcoinExchange(const BitcoinExchange& other); //copy construct
		BitcoinExchange &operator=( const BitcoinExchange& other); //copy assignment
		~BitcoinExchange(); //destructor

		bool ValidateDate(); //yyyy-mm-dd ? valid numbers? 
		bool ValidateAmount(); // positove int or float btw 0-1000?
		bool ValidateLine(); // date | value -> single | found?

		void ConvertAndPrint(); //looks up data, calcs amount

};

#endif