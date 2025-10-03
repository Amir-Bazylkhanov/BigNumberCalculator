#include "BigNumber.h"
#include <cstddef>
#include <iostream>

using namespace std;

bool isSmaller(const string& num1, const string& num2);

BigNumber::BigNumber(const string& num) {
    digits = num;
}

BigNumber BigNumber::operator+(const BigNumber& other) {
    string num1 = this->digits;
    string num2 = other.digits;
    string result = "";
    int carry = 0;
    
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i>=0 || j>=0 || carry>0) {
        int digit1 = (i>=0) ? num1[i]-'0' : 0;
        int digit2 = (j>=0) ? num2[j]-'0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result = char('0'+sum%10) + result;

        i--;
        j--;
    }
    return BigNumber(result);
}

BigNumber BigNumber::operator-(const BigNumber& other) {
    string num1 = this->digits;
    string num2 = other.digits;
    bool neg = false;

    if (isSmaller(num1, num2)) {
        swap(num1, num2);
        neg = true;
    }
    string result = "";

    int i = num1.length() - 1;
    int j = num2.length() - 1;

    int borrow = 0;

    while (i>=0) {
        int digit1 = num1[i]-'0';
        int digit2 = (j>=0) ? num2[j]-'0' : 0;

        int diff = digit1-digit2-borrow;
        if (diff<0) {
            borrow = 1;
            diff += 10;
        } else {
            borrow = 0;
        }

        result = char('0'+diff)+result;

        i--;
        j--;
    }

    size_t firstNoneZero = result.find_first_not_of('0');
        if (firstNoneZero == string::npos) {
            result = "0";
        } else {
            result = result.substr(firstNoneZero);
        }

        
    return neg ? BigNumber('-'+result) : BigNumber(result);
}

void BigNumber::display() {
    cout << digits << endl;
}

bool isSmaller(const string& num1, const string& num2) {
    if (num1.length() != num2.length()) {
        return num1.length() < num2.length();
    }
    return num1 < num2;
}