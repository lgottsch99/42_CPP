
#include "BitcoinExchange.hpp"
#include <string>

// -------------- Constructors --------------

//default
BitcoinExchange::BitcoinExchange()
{
	std::cout << "(BitcoinExchange) Default constructor\n";

	_ReadCsv();

}

//copy construct
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	std::cout << "(BitcoinExchange) Copy constructor\n";
	CsvData = other.CsvData;
}

//copy assignment
BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange& other)
{
	std::cout << "(BitcoinExchange) Copy assignment operator\n";
	if (this != &other)
	{
		CsvData = other.CsvData;
	}
	return (*this);
}

//destructor
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "(BitcoinExchange) Destructor\n";
}


// -------------- Members --------------


bool BitcoinExchange::_ReadCsv()
{
	//load csv file
	std::ifstream		csv_file("./cpp_09/data.csv", std::ifstream::in);
	std::string			line;
	std::string			date;
	std::string			str_value;
	float				value = 0.0f;

	while ( std::getline (csv_file, line)) 
	{
		std::istringstream iss(line); //why istringstream???
  		//parse line  and seperate
		std::getline(iss, date, ',');
		std::cout << "date is: " << date << "\n"; 

		getline(iss, str_value, '\n');
		std::cout << "str value is: " << str_value << "\n"; 
		value = std::atof(str_value.c_str());
		std::cout << "value is: " << value << "\n"; 

		//into map
		CsvData.insert( std::make_pair(date, value));

	}
	return true;
}

void BitcoinExchange::OpenInputFile(std::string & str) //try open input file, if not possible throw exc
{

	std::ifstream input_file(str.c_str(), std::ifstream::in); //ifstream reads from file

	if (!input_file.is_open())
		throw std::runtime_error("Error: Cannot open input file!\n");
	
	//TODO validate format of input file??

}


void BitcoinExchange::ProcessFile(std::string &filename)
{
	//orchestrator for processing 

		//go thru each line in input 
			//validate line format
			//validate date
			//look up in csv 
			//print result
}
