#pragma once

#include <string>
#include <map>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fcntl.h>
#include <fstream>
#include <sstream>
#include <exception>
#include <iterator>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &src);
    ~BitcoinExchange();

    void get_data(std::string const &line);
    const std::map<std::string, double>  *get_bitcoin_values() const;
    //std::map<std::string, double>::iterator iteration(std::string date);

private:
    std::map<std::string, double> bitcoin_values;
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
