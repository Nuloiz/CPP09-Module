#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(PmergeMe const &src) {
    *this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src) {
    if (this != &src) {
    }
    return *this;
}

PmergeMe::~PmergeMe() {
}