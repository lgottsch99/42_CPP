#include "BitcoinExchange.hpp"
#include <string>


char const *BitcoinExchange::InvalidInputLine::what(void) const throw()
{
	// return ("Input File: Line of invalid Format!\n"); //TODO add line
	return (_msg.c_str());
};

char const *BitcoinExchange::InvalidDate::what(void) const throw()
{
	return (_msg.c_str()); //TODO add line
};

char const *BitcoinExchange::InvalidPosValue::what(void) const throw()
{
	return ("Error: not a positive number.\n"); //TODO add line
};

char const *BitcoinExchange::InvalidLargeValue::what(void) const throw()
{
	return ("Error: too large a number.\n"); //TODO add line
};
char const *BitcoinExchange::CsvLoadError::what(void) const throw()
{
	return ("Error: Database loading error\n"); //TODO add line
};
char const *BitcoinExchange::CannotOpenFile::what(void) const throw()
{
	return ("Error: could not open file.\n"); //TODO add line
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


time_t BitcoinExchange::_ConvertDateToTime(std::string &date)
{
	std::string syear = date.substr(0, 4);
	// std::cout << "year is: " << syear << "\n";
	std::string smonth = date.substr(5, 2);
	// std::cout << "month is: " << smonth << "\n";
	std::string sday = date.substr(8, 2);
	// std::cout << "day is: " << sday << "\n";

	int year = std::atoi(syear.c_str());
	int month = std::atoi(smonth.c_str());
	int day = std::atoi(sday.c_str());
	time_t rawtime;
	struct tm *timeinfo = NULL;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	return(mktime(timeinfo));
}

bool BitcoinExchange::_ReadCsv()
{
	//load csv file
	std::ifstream		csv_file("./cpp_09/data.csv", std::ifstream::in);
	std::string			line;
	std::string			date;
	std::string			str_value;
	double				value = 0.0;
	int i = 0;

	while ( std::getline (csv_file, line)) 
	{
		std::istringstream iss(line); //why istringstream???
		std::getline(iss, date, ',');
		
		if (date.size() < 10)
			continue;

		time_t	time_key = _ConvertDateToTime(date);
		if (time_key == -1)
			throw CsvLoadError();

		if (i == 0) //store first entry
			first_entry = time_key;
		else
			last_entry = time_key; //store last for possible future date input

		getline(iss, str_value, '\n');
		// std::cout << "str value is: " << str_value << "\n"; 

		value = std::strtod(str_value.c_str(), NULL);
		// std::cout << "atof value is: " << value << "\n"; 

		//into map
		CsvData.insert(std::make_pair(time_key, value));
		i++;
	}
	if (CsvData.empty())
		throw CsvLoadError();
	return true;
}


//orchestrator for processing
void BitcoinExchange::ProcessFile(std::string &filename)
{
	std::string		input_line;
	
	//try to open infile
	std::ifstream input_file(filename.c_str(), std::ifstream::in); //ifstream reads from file
	if (!input_file.is_open())
		throw CannotOpenFile();

	while (getline(input_file, input_line)) //go thru each line
	{
		//go thru each line in input 
		try
		{
			_ValidateLine(input_line);
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
			continue;
		}
	}
}


void BitcoinExchange::_ValidateLine(std::string& line) // date | value -> single | found?
{
	//go thru line and check if exactly one " | "
	std::string error = "Input File: Line of invalid Format: ";
	error.append(line);
	error.append("\n");

	std::string del = " | ";
	size_t pos_found;
	size_t pos_two;

	pos_found = line.find(del);
 	if (pos_found == std::string::npos)
		throw InvalidInputLine(error);
	else
	{
		//check for second occurrence
		pos_two = line.rfind(del);
		if (pos_found != pos_two)
			throw InvalidInputLine(error);
	}

	//split str in date and value
	std::string date = line.substr(0, pos_found);
	_processedDate = date;
	std::string value = line.substr(pos_found + 3, line.size()); //treating delimiter " | " with spaces as necessary

	//validat date //check value
	if (_ValidateDate(date) && _ValidateAmount(value))
		_ConvertAndPrint(date, value);
}

bool BitcoinExchange::_ValidateDate(std::string& date) //yyyy-mm-dd ? valid numbers? 
{
	int strich = 0;
	std::string error = "Error: Invalid Date! -> ";
	error.append(date);
	error.append("\n");

//check only digits and -
// std::cout << "Date check digit and minus\n";
	size_t i = 0;
	while (i < date.size())
	{
		if (!isdigit(date[i]) && date[i] != '-')
		{
			throw InvalidDate(error);
			return false;
		}
		else if (date[i] == '-')
			strich++;
		i++;
	}
	// std::cout << "Date check 2 minus\n";

	if (strich != 2) //check 2x '-'
	{
		throw InvalidDate(error);
		return false;
	}
	//check - pos
	size_t pos_one;
	size_t pos_two;

	pos_one = date.find("-");
	// std::cout <<"1st min at: " << pos_one << "\n";
	pos_two = date.rfind("-");
	// std::cout <<"2nd min at: " << pos_two << "\n";
	if (pos_one != 4 || pos_two != 7)
	{
		throw InvalidDate(error);
		return false;
	}

	//split and construct timestruct ->  if -1 invalid date
	std::string syear = date.substr(0, 4);
	// std::cout << "year is: " << syear << "\n";
	std::string smonth = date.substr(5, 2);
	// std::cout << "month is: " << smonth << "\n";
	std::string sday = date.substr(8, 2);
	// std::cout << "day is: " << sday << "\n";

	int year = std::atoi(syear.c_str());
	int month = std::atoi(smonth.c_str());
	int day = std::atoi(sday.c_str());
	time_t rawtime;
	struct tm *timeinfo = NULL;

	time(&rawtime); //fills &rawtime with current time
	timeinfo = localtime(&rawtime); //converts into struct tm
	timeinfo->tm_year = year - 1900; //tm_year  = no of years since 1900
	timeinfo->tm_mon = month - 1; //indexed at 0
	timeinfo->tm_mday = day;
 	if (mktime(timeinfo) == -1) //mktime automatically adjust wrong date to correct one -> feb 31 is march 3
	{
		throw InvalidDate(error);
		return false;
	}
	// std::cout << "check if modified date\n";
	//check if mktime corrected values
	if (timeinfo->tm_year != year - 1900 ||
		timeinfo->tm_mon != month - 1 || 
		timeinfo->tm_mday != day)
	{
		throw InvalidDate(error);
		return false;
	}

	_is_past = false;
	_is_future = false;
	if (mktime(timeinfo) < first_entry)
		_is_past = true;
	else if (mktime(timeinfo) > last_entry)
		_is_future = true;

	// std::cout << "********DATE VALID\n\n";
	return true;
}



bool BitcoinExchange::_ValidateAmount(std::string& value) // positove int or float btw 0-1000?
{
	//convert to float/int?
	double num = std::strtod(value.c_str(), NULL);
	// std::cout << "num is: " << num << "\n";
	if (num < 0)
	{
		throw InvalidPosValue();
		return false;
	}	
	else if (num > 1000)
	{
		throw InvalidLargeValue();
		return false;
	}
	else
		return true;
}


void BitcoinExchange::_ConvertAndPrint(std::string& date, std::string& value)
{
	std::cout << date << " => " << value << " = ";
	
	//look up conversion in map by date-key
	std::map<time_t, double>::iterator it;

	time_t datetime = _ConvertDateToTime(date);

	it = CsvData.find(datetime);
	if (it == CsvData.end())
	{// std::cout << "Could not find EXACT date in MAP!\n";

		if (_is_past)
			it = CsvData.begin();
		else if (_is_future)
		{			
			it = CsvData.end();
			it--;
		}
		else //inbetween 2 db values 
		{
			it = CsvData.lower_bound(datetime); //returns first bigger in map
			it--; //mive to lower one
		}
	}
	// std::cout << "Exchange rate is : " << it->second << " result: ";
	//do conversion
	double fvalue = std::strtod(value.c_str(), NULL);

	std::cout << static_cast<float>( fvalue * it->second) << "\n";
\
}