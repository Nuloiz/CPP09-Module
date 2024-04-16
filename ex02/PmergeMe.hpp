#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>
#include <bits/stdc++.h>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(PmergeMe const &src);
    PmergeMe &operator=(PmergeMe const &src);
    ~PmergeMe();

    std::vector<int> get_vector();
    std::list<int> get_list();

private:
    std::vector<int> vector;
    std::list<int> list;
};

/*template <typename T>
void binary_search(T *container, int num)
{
    T *begin = &container[0];
    T *end = &container[container.size() - 1];
    T *mid;


    while (begin < end)
    {
        mid = begin + (end - begin) / 2;
        if (*mid == num)
            throw std::exception();
        else if (*mid < num)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    if (*begin == num)
        throw std::exception();
    if (*begin < num)
        container.insert(begin + 1, num);
    else
        container.insert(begin, num);
}*/