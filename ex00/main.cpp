#include "BitcoinExchange.hpp"

int error_check(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Incorrect number of arguments" << std::endl;
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        std::cerr << "Error: File does not exist" << std::endl;
        return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (error_check(argc, argv))
        return 1;
    BitcoinExchange exchange;
    std::string line;
    while (std::getline(fd, line)) {
        try{
            exchange.check_input(line);
            exchange.get_date(line);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
    }
    close(fd);
}