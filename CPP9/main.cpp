
// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91

#include <fstream>
#include <iostream>
#include <map> // key + value pair, unique keys for storing csv data by date
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc <input_file>\n";
		return 0;
	}

	BitcoinExchange btc;//(obj) load csv file with data
	std::string input_file(argv[1]);

	try 
	{
		//check if input file is valid
		//try to open, if ok:
		btc.OpenInputFile(input_file);
			//(obj) read input line by line:
				//(obj) validate date
				//(obj) validate value
				//(obj) if both ok: look up data value and calculate, print

	}
	catch (std::exception &e)
	{
		std::cout << e.what();
		return 0;
	}

	return 0;
}