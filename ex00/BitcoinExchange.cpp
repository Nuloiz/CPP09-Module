#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        bitcoin_values = other.bitcoin_values;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::get_data(const std::string &line)
{
    std::stringstream s(line.substr(11));
    double value;
    s >> value;
    bitcoin_values.insert(std::pair<std::string, double>(line.substr(0, 10), value));
}

std::map<std::string, double> BitcoinExchange::get_bitcoin_values() const {
    return bitcoin_values;
}


