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
    //void fill_vector(char **argv);
    //void fill_list(char **argv);
    void print_vector();
    void bin_s_vector(int num);
    void bin_s_list(int num);

private:
    std::vector<int> vector;
    std::list<int> list;
};


class DoubleNumber:public std::exception {
    virtual const char* what() const throw() {
        return "Number exists twice";
    }
};