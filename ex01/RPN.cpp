#include "RPN.hpp"

RPN::RPN() : result(0) {
}

RPN::RPN(RPN const &src) {
    *this = src;
}

RPN &RPN::operator=(RPN const &src) {
    if (this != &src) {
        stack_num = src.stack_num;
        stack_op = src.stack_op;
        result = src.result;
    }
    return *this;
}

RPN::~RPN() {
}

void RPN::calculate()
{
    int tmp;

    if (stack_num.size() == 0)
    {
        std::cerr << "Error: No numbers to calculate" << std::endl;
        throw std::exception();
    }
    result = stack_num.top();
    stack_num.pop();
    while (stack_num.size() > 0 && stack_op.size() > 0)
    {
        tmp = stack_num.top();
        stack_num.pop();
        if (stack_op.top() == '+')
            result = result + tmp;
        else if (stack_op.top() == '-')
            result = result - tmp;
        else if (stack_op.top() == '*')
            result = result * tmp;
        else if (stack_op.top() == '/')
            result = result / tmp;
        stack_op.pop();
    }
    if (stack_num.size() > 0 || stack_op.size() > 0)
    {
        std::cerr << "Error: Incorrect RPN format" << std::endl;
        throw std::exception();
    }
}

void RPN::print_result() const
{
    std::cout << result << std::endl;
}

void RPN::fill_stacks(const std::string &line)
{
    int i = line.size() - 1;
    while (i >= 0)
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
                stack_num.push(line[i] - '0');
            else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
                stack_op.push(line[i]);
            else
            {
                std::cerr << "Error: Incorrect line format" << std::endl;
                throw std::exception();
            }
        }
        i--;
    }
}
