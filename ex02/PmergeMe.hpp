#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <exception>
#include <bits/stdc++.h>
#include <iterator>

typedef std::vector<std::pair<int, int> > Pairs;

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(PmergeMe const &src);
    PmergeMe &operator=(PmergeMe const &src);
    ~PmergeMe();

    std::vector<int> get_vector();
    std::deque<int> get_deque();
    void fill_vector(char *argv, int *k);
    void fill_deque(char *argv, int k);
    Pairs create_pairs_vector();
    Pairs create_pairs_deque();
    void sort_vector();
    void sort_deque();
    void print_vector();
    void print_deque();

private:
    std::vector<int> vector;
    std::deque<int> deque;
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