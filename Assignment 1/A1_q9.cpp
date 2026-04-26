#include <iostream>
using namespace std;
int main() {
    float num1, num2, result;
    char operation;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "\nSelect operation:" << endl;
    cout << "+ : Addition" << endl;
    cout << "- : Subtraction" << endl;
    cout << "* : Multiplication" << endl;
    cout << "/ : Division" << endl;
    cout << "% : Modulus (only for integers)" << endl;
    cout << "\nEnter operation: ";
    cin >> operation;
    switch(operation) {
     case '+':
            result = num1 + num2;
            cout << num1 << " + " << num2 << " = " << result << endl;
            break;
     case '-':
            result = num1 - num2;
            cout << num1 << " - " << num2 << " = " << result << endl;
            break;
    case '*':
            result = num1 * num2;
            cout << num1 << " * " << num2 << " = " << result << endl;
            break;
    case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed!" << endl;
            }
            break;
     case '%':
            if (num2 != 0) {
                result = (int)num1 % (int)num2;
                cout << (int)num1 << " % " << (int)num2 << " = " << (int)result << endl;
            } else {
                cout << "Error: Modulus by zero is not allowed!" << endl;
            }
            break;
        default:
            cout << "Error: Invalid operation!" << endl;
            break;
    }
    return 0;
}
