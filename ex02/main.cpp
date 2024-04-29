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

static unsigned long long get_current_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000 + tv.tv_usec);
}

static void printTime(unsigned long long us)
{
    double duration = static_cast<double>(us);
    if (us >= 60000000) {
        std::cout << std::setprecision(5) << duration / 60000000.0 << " m";
    } else if (us >= 1000000) {
        std::cout << std::setprecision(5) << duration / 1000000.0 << " s";
    } else if (us >= 1000) {
        std::cout << std::setprecision(5) << duration / 1000.0 << " ms";
    } else {
        std::cout << us << " us";
    }
    std::cout << std::endl;
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
        std::cout << "Vector before: ";
        p.print_vector();
        unsigned long long vtime = get_current_time();
        pairs = p.create_pairs_vector();
        pairs = sort_all_pairs(pairs);
        p.sort_vector(pairs);
        vtime = get_current_time() - vtime;
        std::cout << "Vector after: ";
        p.print_vector();
        std::cout << "Time to process a range of " << p.get_vector().size() << " elements with std::vector : ";
        printTime(vtime);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        std::cout << "Deque before: ";
        p.print_deque();
        unsigned long long dtime = get_current_time();
        pairs = p.create_pairs_deque();
        pairs = sort_all_pairs(pairs);
        p.sort_deque(pairs);
        dtime = get_current_time() - dtime;
        std::cout << "Deque after: ";
        p.print_deque();
        std::cout << "Time to process a range of " << p.get_deque().size() << " elements with std::deque : ";
        printTime(dtime);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}