#include <iostream>
using namespace std;
int main() {
    int intValue;
    float decimalValue;
    char charValue;
    cout << "Enter an integer: ";
    cin >> intValue;
    cout << "Enter a decimal number: ";
    cin >> decimalValue;
    cout << "Enter a character: ";
    cin >> charValue;
    cout << "\n--- Displaying Values ---" << endl;
    cout << "Integer: " << intValue << endl;
    cout << "Decimal: " << decimalValue << endl;
    cout << "Character: " << charValue << endl;
    return 0;
}
