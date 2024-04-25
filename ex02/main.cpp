#include "PmergeMe.hpp"

static void input_check(char **argv, PmergeMe *p)
{
    int i = 0;
    int k;
    while (argv[i])
    {
        k = 0;
        while (argv[i][k])
        {
            if (!isdigit(argv[i][k]) && !iswspace(argv[i][k]))
                throw InvalidInput();
            if (argv[i][k] != ' ')
            {
                p->fill_deque(argv[i], k);
                p->fill_vector(argv[i], &k);
            }
            else
                k++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    argv++;
    if (argc < 2)
    {
        std::cout << "Error: No arguments provided" << std::endl;
        return (1);
    }
    PmergeMe p;
    Pairs pairs;
    try
    {
        input_check(argv, &p);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return (1);
    }
    try
    {
        std::cout << "Vector:" << std::endl;
        p.print_vector();
        std::cout << "----------------" << std::endl;
        pairs = p.create_pairs_vector();
        for (Pairs::iterator it = pairs.begin(); it != pairs.end(); it++)
            std::cout << it->first << " " << it->second << std::endl;
        std::cout << "----------------" << std::endl;
        pairs = sort_all_pairs(pairs);
        p.sort_vector(pairs);
        p.print_vector();
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        std::cout << "Deque:" << std::endl;
        p.print_deque();
        std::cout << "----------------" << std::endl;
        pairs = p.create_pairs_deque();
        for (Pairs::iterator it = pairs.begin(); it != pairs.end(); it++)
            std::cout << it->first << " " << it->second << std::endl;
        std::cout << "----------------" << std::endl;
        pairs = sort_all_pairs(pairs);
        p.sort_deque(pairs);
        p.print_deque();
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}