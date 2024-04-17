#include "PmergeMe.hpp"

static void input_check(char **argv, PmergeMe *p)
{
    int i = 0;
    int k;
    while (argv[i])
    {
        std::cout << argv[i] << std::endl;
        k = 0;
        while (argv[i][k])
        {
            std::cout << argv[i][k] << std::endl;
            if (!isdigit(argv[i][k]) && argv[i][k] != ' ')
                throw InvalidInput();
            if (argv[i][k] != ' ')
            {
                p->fill_vector(argv[i], &k);
                //p->fill_list(argv[i], &k);
            }
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
    try
    {
        PmergeMe p;
        input_check(argv, &p);
        p.print_vector();
        std::cout << "----------------" << std::endl;
        p.bin_s_vector(4);
        p.print_vector();
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}