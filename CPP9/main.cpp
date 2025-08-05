
// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91


#include <iostream>
#include <map> // key + value pair, unique keys for storing csv data by date

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc <input_file>\n";
		return 0;
	}

	//check if input file is valid
		//try to open, if ok:
			//load csv file with data
			//read input line by line:
				//validate date
				//validate value
				//if both ok: look up data value and calculate, print
	return 0;
}