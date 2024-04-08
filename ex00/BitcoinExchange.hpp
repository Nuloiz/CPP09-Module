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

    //void get_date(std::string const &line);

private:
    std::string date;

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
