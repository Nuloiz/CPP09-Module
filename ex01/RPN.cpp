#include "RPN.hpp"

RPN::RPN(){
}

RPN::RPN(RPN const &src) {
    *this = src;
}

RPN &RPN::operator=(RPN const &src) {
    if (this != &src) {
        stack = src.stack;
    }
    return *this;
}

RPN::~RPN() {
}

void RPN::calculate(char op)
{
    int first;
    int second;
    int result;

    if (stack.size() < 2)
    {
        std::cerr << "Error: Not enough numbers to calculate" << std::endl;
        throw std::exception();
    }
    second = stack.top();
    stack.pop();
    first = stack.top();
    stack.pop();
    if (op == '+')
        result = first + second;
    else if (op == '-')
        result = first - second;
    else if (op == '*')
        result = first * second;
    else if (op == '/')
        result = first / second;
    stack.push(result);
    std::cout << first << op << second << " = " << result << std::endl;
}

void RPN::print_result() const
{
    if (stack.size() != 1)
    {
        std::cerr << "Error: Incorrect line format" << std::endl;
        throw std::exception();
    }
    std::cout << stack.top() << std::endl;
}

void RPN::fill_stacks(const std::string &line)
{
    int i = 0;
    while (i < (int)line.size())
    {
        if (i % 2 != 0)
        {
            if (line[i] != ' ')
            {
                std::cerr << "Error: Incorrect line format" << std::endl;
                throw std::exception();
            }
        }
        else
        {
            if (line[i] >= '0' && line[i] <= '9')
                stack.push(line[i] - '0');
            else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
                calculate(line[i]);
            else
            {
                std::cerr << "Error: Incorrect line format" << std::endl;
                throw std::exception();
            }
        }
        i++;
    }
}
