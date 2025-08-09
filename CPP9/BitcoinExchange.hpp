

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>      // std::stringstream
#include <utility>
#include <cstdlib> //atoi atof
#include <iomanip> 
#include <stdexcept> // for std::runtime_error
#include <exception>
#include <time.h>       /* time_t, struct tm, time, mktime */

class BitcoinExchange
{	
	private:
		
		bool		_ReadCsv();
		time_t		_ConvertDateToTime(std::string &date);
		std::string	_processedDate; //storing date to validate (for exception printing)
		
		bool _ValidateDate(std::string& date); //yyyy-mm-dd ? valid numbers? 
		bool _ValidateAmount(std::string& value); // positove int or float btw 0-1000?
		void _ValidateLine(std::string& line); // date | value -> single | found?
		void _ConvertAndPrint(std::string& date, std::string& value); //looks up data, calcs amount

	public:
		// std::map<std::string, float>	CsvData; //make private
		std::map<time_t, double>	CsvData;

		BitcoinExchange(void);//default
		BitcoinExchange(const BitcoinExchange& other); //copy construct
		BitcoinExchange &operator=( const BitcoinExchange& other); //copy assignment
		~BitcoinExchange(); //destructor

		void ProcessFile( std::string &filename);

		class InvalidInputLine : public std::exception 
		{
			private:
				std::string _msg;
			public:
				InvalidInputLine(std::string& msg): _msg(msg) {};
				virtual ~InvalidInputLine() throw() {}; //need to add destructor with throw or it would not compoile,  throw() indicates ft does NOT throw excepts
				const char * what(void) const throw();
		};
		
		class InvalidDate : public std::exception 
		{
			private:
				std::string _msg;
			public:
				InvalidDate(std::string& msg): _msg(msg) {};
				virtual ~InvalidDate() throw() {}; //need to add destructor with throw or it would not compoile,  throw() indicates ft does NOT throw excepts
				const char * what(void) const throw();
		};
		class InvalidPosValue : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};
		class InvalidLargeValue : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};
		class CsvLoadError : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};
		class CannotOpenFile : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};


};

#endif