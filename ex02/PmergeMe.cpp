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

std::deque<int> PmergeMe::get_deque()
{
    return deque;
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

void PmergeMe::fill_deque(char *argv, int k)
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
    deque.push_back(num);
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

void PmergeMe::print_deque()
{
    std::deque<int>::iterator it = deque.begin();
    while (it != deque.end())
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

void PmergeMe::bin_s_deque(int num)
{
    std::deque<int>::iterator begin = deque.begin();
    std::deque<int>::iterator end = deque.end();
    std::deque<int>::iterator mid;
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
        deque.insert(begin + 1, num);
    else
        deque.insert(begin, num);
}

