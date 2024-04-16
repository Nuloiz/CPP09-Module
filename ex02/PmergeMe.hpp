#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>
#include <bits/stdc++.h>
#include <iterator>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(PmergeMe const &src);
    PmergeMe &operator=(PmergeMe const &src);
    ~PmergeMe();

    std::vector<int> get_vector();
    std::list<int> get_list();
    void insert_vector(int value);
    void insert_list(int value);

private:
    std::vector<int> vector;
    std::list<int> list;
};
