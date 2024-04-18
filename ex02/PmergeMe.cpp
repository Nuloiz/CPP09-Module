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



