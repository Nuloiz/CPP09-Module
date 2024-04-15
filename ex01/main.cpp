#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Incorrect number of arguments" << std::endl;
        return 1;
    }
    RPN rpn;
    try
    {
        rpn.fill_stacks(argv[1]);
        rpn.print_result();
    }
    catch (std::exception &e)
    {
        return 1;
    }
    return 0;
}