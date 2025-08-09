#include "RPN.hpp"

// -------------- Constructors --------------

//default
RPN::RPN()
{
	std::cout << "(RPN) Default constructor\n";
}

//copy construct
RPN::RPN(const RPN& other)
{
	std::cout << "(RPN) Copy constructor\n";
	_stack = other._stack;
}

//copy assignment
RPN &RPN::operator=( const RPN& other)
{
	std::cout << "(RPN) Copy assignment operator\n";
	if (this != &other)
	{
		_stack = other._stack;
	}
	return (*this);
}

//destructor
RPN::~RPN()
{
	std::cout << "(RPN) Destructor\n";
}

// -------------- MEMBERS --------------


bool InputValid(std::string input) //TODO: check for valid operators!!!!!
{
	size_t i = 0;
	while (i < input.size())
	{
		if (!isdigit(input[i]) 
			&& input[i] != '+' 
			&& input[i] != '-'
			&& input[i] != '*'
			&& input[i] != '/'
			&& input[i] != ' ')
		{
			// std::cerr << "Error: Char not allowed in str\n";
			return false;
		}
		i++;
	}
	return true;
}


bool IsOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

void RPN::_addition(void)
{
	float one = _stack.top();
	// std::cout << "Plus one: " << one << "\n";
	_stack.pop();
	float two = _stack.top();
	// std::cout << "Plus two: " << two << "\n";
	_stack.pop();
	_stack.push(static_cast<float>(one + two));
}

void RPN::_substraction(void)
{
	// std::cout << "MINUS!\n";
	float one = _stack.top();
	// std::cout << "Minus one: " << one << "\n";
	_stack.pop();
	float two = _stack.top();
	// std::cout << "Minus two: " << two << "\n";
	_stack.pop();
	_stack.push(static_cast<float>(two - one));
}


void RPN::_multiplication(void)
{
	// std::cout << "MULTIP!\n";
	float one = _stack.top();
	// std::cout << "Mult one: " << one << "\n";
	_stack.pop();
	float two = _stack.top();
	// std::cout << "Mult two: " << two << "\n";
	_stack.pop();
	_stack.push(static_cast<float>(one * two));

}
void RPN::_division(void)
{
	// std::cout << "DIVISION!\n";
	float one = _stack.top();
	// std::cout << "Div one: " << one << "\n";
	_stack.pop();
	float two = _stack.top();
	// std::cout << "Div two: " << two << "\n";
	_stack.pop();
	_stack.push(static_cast<float>(two / one));

}

int	RPN::_ParseAndCalc(std::string &input)
{
	// std::cout << "parsing and calcing\n";

	//go thru str
	size_t i = 0;
	while (i < input.size())
	{
		//encounter digit? ->add to stack
		if (isdigit(input[i]))
		{
			int value = input[i] - '0';
			_stack.push(value);
		}
		//encounter operator? -pop last two and calc, push result back to stack
		else if (IsOperator(input[i]) && _stack.size() >= 2)
		{
			if (input[i] == '+')
				_addition();
			else if (input[i] == '-')
				_substraction();
			else if (input[i] == '*')
				_multiplication();
			else if (input[i] == '/')
				_division();
		}
		i++;
	}	

	if (_stack.size() != 1)
	{
		std::cerr << "Error\n";
		return 1;
	}
	std::cout << std::setprecision(4)<<  _stack.top() << std::endl; //result is last elem in stack
	return 0;
}

int RPN::Process(std::string &input)
{
	// std::cout << "Processing input.. " << input << "\n";
	int status = 0;
	//check if input valid 
		//check if only digits, space and +-*/
	if (!InputValid(input))
	{
		std::cerr << "Error\n";
		return 1;
	}
	//parse and calc 
	status = _ParseAndCalc(input);
	return status;
}
