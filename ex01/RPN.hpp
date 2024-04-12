#pragma once

#include <iostream>
#include <stack>
#include <algorithm>

class RPN
{
public:
    RPN();
    RPN(RPN const &src);
    RPN &operator=(RPN const &src);
    ~RPN();

    void calculate(std::string const &line);
    void print_result() const;

private:
    std::stack<int> stack;
    int result;
};