#include "BitcoinExchange.hpp"

static int error_check(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Incorrect number of arguments" << std::endl;
        return 1;
    }
    std::ifstream fd;
    fd.open(argv[1]);
    if (fd.fail())
    {
        std::cerr << "Error: File does not exist" << std::endl;
        return 1;
    }
    fd.close();
    return 0;
}

static int first_line_check(std::string line) {
    if (line != "date | value")
    {
        std::cerr << "Error: Incorrect first line" << std::endl;
        return 1;
    }
    return 0;
}

static void check_input(std::string line)
{
    std::stringstream convert;
    int year, month, day;
    float value;

    convert.str(line.substr(0, 4));
    convert >> year;
    convert.clear();
    convert.str(line.substr(5, 2));
    convert >> month;
    convert.clear();
    convert.str(line.substr(8, 2));
    convert >> day;
    convert.clear();
    if (line[10] == ',')
        convert.str(line.substr(10, line.size() - 10));
    else
        convert.str(line.substr(13, line.size() - 13));
    convert >> value;
    if (line[4] != '-' || line[7] != '-' || ((line[10] != ' ' || line[11] != '|' || line[12] != ' ') && line[10] != ','))
        throw IncorrectLineEX(); //incorrect line format
    else if (month < 1 || month > 12 || day < 1 || day > 31)
        throw DateNotPossibleEX(); // date not possible
    else if ((month < 7 && month % 2 == 0 && day == 31) || (month > 8 && month % 2 == 1 && day == 31))
        throw DateNotPossibleEX(); // date not possible
    else if (month == 2 && (((year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) && day == 29) || day > 29))
        throw DateNotPossibleEX(); // date not possible
    else if (year < 2009 || (year == 2009 && month == 1 && day == 1))
        throw DateTooEarlyEX(); // date too early
    else if (value < 0 || value > 1000)
        throw ValueOutOfRangeEX(); // value out of range
}

static int check_db(BitcoinExchange *exchange)
{
    int i = 0;
    std::ifstream fd;
    std::string line;
    fd.open("data.csv");
    std::getline(fd, line);
    if (fd.fail())
    {
        std::cerr << "Error: Database does not exist" << std::endl;
        return 1;
    }
    else if (line != "date,exchange_rate")
    {
        std::cerr << "Error: Incorrect database format" << std::endl;
        return 1;
    }
    try
    {
        while (std::getline(fd, line))
        {
            check_input(line);
            i++;
            exchange->get_data(line);
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "in line: " << i << " : " << line << std::endl;
        return 1;
    }
    fd.close();
    return 0;
}

int main(int argc, char **argv)
{
    if (error_check(argc, argv))
        return 1;
    BitcoinExchange exchange;
    exchange.set_iterator(0);
    std::string line;
    std::ifstream fd;
    fd.open(argv[1]);
    std::getline(fd, line);
    if (first_line_check(line))
        return 1;
    if (check_db(&exchange))
        return 1;
    while (std::getline(fd, line)) {
        try{
            check_input(line);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    std::cout << exchange.get_bitcoin_values() << std::endl;
    fd.close();
}