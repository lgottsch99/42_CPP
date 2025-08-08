
#include "BitcoinExchange.hpp"
#include <string>



char const *BitcoinExchange::GradeTooHighException::what(std::string &line) const throw()
{
	std::string msg = "Input File: Line of invalid Format! -> ";

	msg.append(line);
	msg.append("\n");

	greturn (msg);
};



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

std::ifstream& BitcoinExchange::OpenInputFile(std::string & str) //try open input file, if not possible throw exc
{

	std::ifstream input_file(str.c_str(), std::ifstream::in); //ifstream reads from file

	if (!input_file.is_open())
		throw std::runtime_error("Error: Cannot open input file!\n");
	
	//TODO validate format of input file??
	return (input_file);
}

//orchestrator for processing
void BitcoinExchange::ProcessFile(std::ifstream& infile, std::string &filename)
{
	(void) filename;
	std::string		input_line;

	while (getline(infile, line)) //go thru each line
	{
		//go thru each line in input 
		try
		{
			ValidateLine(line);

			//validate line format
			//validate date
			//look up in csv 
			//print result
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
			continue;
		}




	}

}


void BitcoinExchange::ValidateLine(std::string& line) // date | value -> single | found?
{
	//go thru line and check if exactly one " | "
	//else except
	std::string del = " | ";
	size_t pos_found;
	size_t pos_two;

	pos_found = line.find(del);
 	if (pos_found = std::string::npos)
		throw InvalidInputLine(line);
	else
	{
		//check for second occurrence
		pos_two = line.rfind(del);
		if (pos_found != pos_two)
			throw InvalidInputLine(line);
	}

}
