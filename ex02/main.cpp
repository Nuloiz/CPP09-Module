#include "PmergeMe.hpp"

int input_check(char **argv)
{
    int i = 1;
    int k;
    while (argv[i])
    {
        k = 0;
        while (argv[i][k])
        {
            if (!isdigit(argv[i][k] && argv[i][k] != ' '))
                return (1);
            k++;
        }
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    argv++;
    if (argc < 2)
    {
        std::cout << "Error: No arguments provided" << std::endl;
        return (1);
    }
    if (input_check(argv))
    {
        std::cout << "Error: Invalid input" << std::endl;
        return (1);
    }
    try
    {
        PmergeMe p;
        std::cout << binary_search(p.get_vector().begin(), p.get_vector().end(), 2);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}