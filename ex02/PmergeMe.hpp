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
    void fill_vector(char *argv, int *k);
    void fill_list(char *argv, int k);
    void print_vector();
    void print_list();
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

class InvalidInput:public std::exception {
    virtual const char* what() const throw() {
        return "Invalid Input";
    }
};