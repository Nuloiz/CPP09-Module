#pragma once

#include <string>
#include <map>
#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <fstream>
#include <sstream>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &src);
    ~BitcoinExchange();

    typedef typename std::map<std::string, double>::container_type::iterator iterator;

    iterator begin()
    {
        return std::map<std::string, double>::c.begin();
    }

    iterator end()
    {
        return std::map<std::string, double>::c.end();
    }

    void get_data(std::string const &line);
    int get_bitcoin_values() const;
    void set_iterator(int i);

private:
    std::map<std::string, double> bitcoin_values;
    int iterator;
};

class IncorrectLineEX :public std::exception {
    virtual const char* what() const throw() {
        return "Incorrect line format";
    }
};

class DateNotPossibleEX :public std::exception {
    virtual const char* what() const throw() {
        return "Date not possible";
    }
};

class DateTooEarlyEX :public std::exception {
    virtual const char* what() const throw() {
        return "Date too early";
    }
};

class ValueOutOfRangeEX :public std::exception {
    virtual const char* what() const throw() {
        return "Value out of range";
    }
};
