
// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91

#include <fstream>
#include <iostream>
#include <map> // key + value pair, unique keys for storing csv data by date
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	BitcoinExchange btc;

	try 
	{
		if (argc != 2)
		{
			// std::cout << "Usage: ./btc <input_file>\n";
			throw BitcoinExchange::CannotOpenFile();
		}
		std::string input_file(argv[1]);
		btc.ProcessFile( input_file);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
		return 0;
	}
	return 0;
}