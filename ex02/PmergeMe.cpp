#include "PmergeMe.hpp"

static void sort_pairs(Pairs &pairs);
static Pairs merge_pairs(Pairs &left, Pairs &right);
static int *jacobsthal_gen(int size);

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

Pairs PmergeMe::create_pairs_vector()
{
    Pairs pairs;
    while (vector.size() > 1)
    {
        std::pair<int, int> pair;
        pair.first = *vector.begin();
        vector.erase(vector.begin());
        pair.second = *vector.begin();
        vector.erase(vector.begin());
        pairs.push_back(pair);
    }
    if (vector.size() == 1)
    {
        std::pair<int, int> pair;
        pair.first = *vector.begin();
        vector.erase(vector.begin());
        pair.second = -1;
        pairs.push_back(pair);
    }
    sort_pairs(pairs);
    return (pairs);
}

Pairs PmergeMe::create_pairs_deque()
{
    Pairs pairs;
    while (deque.size() > 1)
    {
        std::pair<int, int> pair;
        pair.first = *deque.begin();
        deque.erase(deque.begin());
        pair.second = *deque.begin();
        deque.erase(deque.begin());
        pairs.push_back(pair);
    }
    if (deque.size() == 1)
    {
        std::pair<int, int> pair;
        pair.first = *deque.begin();
        deque.erase(deque.begin());
        pair.second = -1;
        pairs.push_back(pair);
    }
    sort_pairs(pairs);
    return (pairs);
}

void PmergeMe::sort_vector(Pairs &pairs)
{
    Pairs tmp;

    if (pairs[0].first != -1)
        vector.push_back(pairs[0].first);
    vector.push_back(pairs[0].second);
    pairs.erase(pairs.begin());
    while (pairs.size() > 0)
    {
        if (pairs[0].first == -1)
        {
            vector.push_back(pairs[0].second);
            pairs.erase(pairs.begin());
        }
        else
        {
            tmp.push_back(pairs[0]);
            vector.push_back(pairs[0].second);
            pairs.erase(pairs.begin());
        }
    }
    vector_jacobsthal(tmp);
}

void PmergeMe::sort_deque(Pairs &pairs)
{
    Pairs tmp;

    if (pairs[0].first != -1)
        deque.push_back(pairs[0].first);
    deque.push_back(pairs[0].second);
    pairs.erase(pairs.begin());
    while (pairs.size() > 0)
    {
        if (pairs[0].first == -1)
        {
            deque.push_back(pairs[0].second);
            pairs.erase(pairs.begin());
        }
        else
        {
            tmp.push_back(pairs[0]);
            deque.push_back(pairs[0].second);
            pairs.erase(pairs.begin());
        }
    }
    deque_jacobsthal(tmp);
}

void PmergeMe::vector_jacobsthal(Pairs &tmp)
{
    int *jacobsthal = jacobsthal_gen(tmp.size());
    int it = 0;
    int num;
    int vsiz = (int)vector.size();
    while ((int)vector.size() < vsiz + (int)tmp.size())
    {
        num = jacobsthal[it] - 2;
        while (num > jacobsthal[it - 1] - 2 && num >= 0)
        {
            vector.insert(std::lower_bound(vector.begin(), std::find(vector.begin(), vector.end(), tmp[num].second), tmp[num].first), tmp[num].first);
            num--;
        }
        it++;
    }
    delete jacobsthal;
}

void PmergeMe::deque_jacobsthal(Pairs &tmp)
{
    int *jacobsthal = jacobsthal_gen(tmp.size());
    int it = 0;
    int num;
    int dsiz = (int)deque.size();
    while ((int)deque.size() < dsiz + (int)tmp.size())
    {
        num = jacobsthal[it] - 2;
        while (num > jacobsthal[it - 1] - 2 && num >= 0)
        {
            deque.insert(std::lower_bound(deque.begin(), std::find(deque.begin(), deque.end(), tmp[num].second), tmp[num].first), tmp[num].first);
            num--;
        }
        it++;
    }
    delete jacobsthal;
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

static void sort_pairs(Pairs &pairs)
{
    int i = 0;
    while (i < (int)pairs.size())
    {
        if (pairs[i].first > pairs[i].second)
        {
            int tmp = pairs[i].first;
            pairs[i].first = pairs[i].second;
            pairs[i].second = tmp;
        }
        i++;
    }
}

Pairs sort_all_pairs(Pairs &pairs)
{
    if (pairs.size() == 1)
        return (pairs);
    Pairs left(pairs.begin(), pairs.begin() + (pairs.size() / 2));
    Pairs right(pairs.begin() + (pairs.size() / 2), pairs.end());
    left = sort_all_pairs(left);
    right = sort_all_pairs(right);
    return (merge_pairs(left, right));
}

static Pairs merge_pairs(Pairs &left, Pairs &right)
{
    Pairs merged;
    while (left.size() > 0 && right.size() > 0)
    {
        if (left[0].second < right[0].second)
        {
            merged.push_back(left[0]);
            left.erase(left.begin());
        }
        else
        {
            merged.push_back(right[0]);
            right.erase(right.begin());
        }
    }
    while (left.size() > 0)
    {
        merged.push_back(left[0]);
        left.erase(left.begin());
    }
    while (right.size() > 0)
    {
        merged.push_back(right[0]);
        right.erase(right.begin());
    }
    return (merged);
}

    static int *jacobsthal_gen(int size)
    {
        int *jacobsthal = new int[size];
        jacobsthal[0] = 3;
        jacobsthal[1] = 5;
        for (int i = 2; i < size; i++)
            jacobsthal[i] = jacobsthal[i - 1] + (jacobsthal[i - 2] * 2);
        return (jacobsthal);
    }