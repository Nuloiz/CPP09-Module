#include "BitcoinExchange.hpp"

static int error_check(int argc, char **argv) {
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

static int first_line_check(std::string const &line) {
    if (line != "date | value")
    {
        std::cerr << "Error: Incorrect first line" << std::endl;
        return 1;
    }
    return 0;
}

static void check_input(std::string const &line)
{
    stringstream convert;
    int year, month, day;
    float value;

    convert.str(line.substr(0, 4));
    year >> convert;
    convert.clear();
    convert.str(line.substr(5, 2));
    month >> convert;
    convert.clear();
    convert.str(line.substr(8, 2));
    day >> convert;
    convert.clear();
    convert.str(line.substr(13));
    value >> convert;
    if (line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
        throw std::exception(); //incorrect line format
    else if (month < 1 || month > 12 || day < 1 || day > 31)
        throw std::exception(); // date not possible
    else if ((month < 7 && month % 2 == 0 && day == 31) || (month > 8 && month % 2 == 1 && day == 31))
        throw std::exception(); // date not possible
    else if (month == 2 && (year % 4 != 0 || year % 100 == 0) && day > 28)
        throw std::exception(); // date not possible
    else if (year < 2009 || (year == 2009 && month == 1 && day == 1))
        throw std::exception(); // date too early
    }
}

int main(int argc, char **argv)
{
    if (error_check(argc, argv))
        return 1;
    BitcoinExchange exchange;
    std::string line;
    int fd = open(argv[1], O_RDONLY);
    if (first_line_check(std::getline(fd, line)))
        return 1;
    while (std::getline(fd, line)) {
        try{
            check_input(line);
            exchange.get_date(line);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
    }
    close(fd);
}