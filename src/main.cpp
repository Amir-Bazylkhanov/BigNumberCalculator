#include "BigNumber.h"
#include <iostream>

using namespace std;


int main(){
    string num1 = "123456789012345678901234567890";
    string num2 = "987654321098765432109876543210";
    cout << "First number: " << num1 << endl;
    cout << "Second number: " << num2 << endl;

    BigNumber bnum1(num1);
    BigNumber bnum2(num2);

    BigNumber sum = bnum1 + bnum2;
    cout << "The sum: ";
    sum.display();

    BigNumber subtraction = bnum1 - bnum2;
    cout << "The subtraction: ";
    subtraction.display();
    return 0;
}