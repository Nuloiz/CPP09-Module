#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    vector.push_back(1);
    vector.push_back(0);
    vector.push_back(3);
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
        {
    if (this != &src) {
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

std::vector<int> PmergeMe::get_vector()
{
    return vector;
}

std::list<int> PmergeMe::get_list()
{
    return list;
}
