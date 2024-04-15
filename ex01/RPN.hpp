#pragma once

#include <iostream>
#include <stack>
#include <algorithm>
#include <exception>

class RPN
{
public:
    RPN();
    RPN(RPN const &src);
    RPN &operator=(RPN const &src);
    ~RPN();

    void calculate(char op);
    void print_result() const;
    void fill_stacks(std::string const &line);

private:
    std::stack<int> stack;
};