

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	RPN rpn;
	std::string input;

	if (argc != 2)
	{
		std::cout << "Usage: ./RPN <string of rpn>\n";
		return 0;
	}
	input = argv[1];
	return (rpn.Process(input));
}
