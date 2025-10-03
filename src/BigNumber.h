#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <string>
using namespace std;

class BigNumber {
    private:
    string digits;
    public:
    BigNumber(const string& num);
    BigNumber operator+(const BigNumber& other);
    BigNumber operator-(const BigNumber& other);
    void display();
};

#endif