#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
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

void PmergeMe::fill_vector(char *argv, int *k)
{
    int num = 0;
    while (argv[*k])
    {
        if (isdigit(argv[*k]))
            num = num * 10 + argv[*k] - '0';
        else
            break;
        (*k)++;
    }
    vector.push_back(num);
}

void PmergeMe::fill_list(char *argv, int k)
{
    int num = 0;
    while (argv[k])
    {
        if (isdigit(argv[k]))
            num = num * 10 + argv[k] - '0';
        else
            break;
        k++;
    }
    list.push_back(num);
}

void PmergeMe::print_vector()
{
    std::vector<int>::iterator it = vector.begin();
    while (it != vector.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
}

void PmergeMe::print_list()
{
    std::list<int>::iterator it = list.begin();
    while (it != list.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
}

void PmergeMe::bin_s_vector(int num)
{
    std::vector<int>::iterator begin = vector.begin();
    std::vector<int>::iterator end = vector.end();
    std::vector<int>::iterator mid;
    while (begin < end)
    {
        mid = begin + (end - begin) / 2;
        if (*mid == num)
            throw DoubleNumber();
        else if (*mid < num)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    if (*begin == num)
        throw std::exception();
    if (*begin < num)
        vector.insert(begin + 1, num);
    else
        vector.insert(begin, num);
}

/*void PmergeMe::bin_s_list(int num)
{
    std::list<int>::iterator begin = list.begin();
    std::list<int>::iterator end = list.end();
    std::list<int>::iterator mid;
    while (*begin < *end)
    {
        mid = begin + (end - begin) / 2;
        if (*mid == num)
            throw DoubleNumber();
        else if (*mid < num)
        {
            mid++;
            begin = mid;
        }
        else
        {
            mid--;
            end = mid;
        }
    }
    if (*begin == num)
        throw std::exception();
    if (*begin < num)
    {
        begin++;
        list.insert(begin, num);
    }
    else
        list.insert(begin, num);
}*/

