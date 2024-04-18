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
                p->fill_list(argv[i], k);
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
    try
    {
        PmergeMe p;
        input_check(argv, &p);
        std::cout << "Vector:" << std::endl;
        p.print_vector();
        std::cout << "List:" << std::endl;
        p.print_list();
        std::cout << "----------------" << std::endl;
        p.bin_s_vector(4);
        //p.bin_s_list(4);
        std::cout << "Vector:" << std::endl;
        p.print_vector();
        std::cout << "List:" << std::endl;
        p.print_list();
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}