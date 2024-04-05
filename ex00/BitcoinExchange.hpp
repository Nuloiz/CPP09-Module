#pragma once

#include <string>
#include <map>
#include <iostream>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &src);
    ~BitcoinExchange();

    void check_input(std::string const &line);
    void get_date(std::string const &line);

private:
    std::string date;
    std::map<std::string> db;

};
