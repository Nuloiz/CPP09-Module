#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
    std::cout << "BitcoinExchange operator= called" << std::endl;
    if (this != &src) {
        this->date = src.date;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "BitcoinExchange destructor called" << std::endl;
}
