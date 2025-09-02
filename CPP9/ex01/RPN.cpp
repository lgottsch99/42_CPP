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


bool InputValid(std::string input)
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
			// std::cout << "weird char detected\n";
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
	double one = _stack.top();
	_stack.pop();
	double two = _stack.top();
	_stack.pop();
	_stack.push(static_cast<double>(one + two));
}

void RPN::_substraction(void)
{
	double one = _stack.top();
	_stack.pop();
	double two = _stack.top();
	_stack.pop();
	_stack.push(static_cast<double>(two - one));
}


void RPN::_multiplication(void)
{
	double one = _stack.top();
	_stack.pop();
	double two = _stack.top();
	_stack.pop();
	_stack.push(static_cast<double>(one * two));
}
void RPN::_division(void) //maybe change to double for more 
{
	double one = _stack.top();
	_stack.pop();
	double two = _stack.top();
	_stack.pop();
	_stack.push(static_cast<double>(two / one));
}

int	RPN::_ParseAndCalc(std::string &input)
{
	//go thru str
	size_t i = 0;
	while (i < input.size())
	{
		//encounter digit? ->add to stack
		if (isdigit(input[i]))
		{
			double value = input[i] - '0';
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

	if (_stack.size() != 1)//then the input was wrong rpn
	{
		std::cerr << "Error\n";
		return 1;
	}
	std::cout << std::setprecision(4)<<  _stack.top() << std::endl; //result is last elem in stack
	return 0;
}

int RPN::Process(std::string &input)
{
	int status = 0;
	if (!InputValid(input))
	{
		std::cerr << "Error\n";
		return 1;
	}
	status = _ParseAndCalc(input);
	return status;
}
