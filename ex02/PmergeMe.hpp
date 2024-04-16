#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(PmergeMe const &src);
    PmergeMe &operator=(PmergeMe const &src);
    ~PmergeMe();

private:
    std::vector<int> vector;
    std::list<int> list;
};
