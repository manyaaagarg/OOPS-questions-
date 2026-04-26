#include <iostream>
using namespace std;
int main() {
    int a, b;
    cout << "Enter value for a: ";
    cin >> a;
    cout << "Enter value for b: ";
    cin >> b;
    cout << "\n=== Demonstrating Assignment Operators ===" << endl;
    cout << "Initial values: a = " << a << ", b = " << b << endl;
    cout << "\n1. Using += operator:" << endl;
    a += 10;  
    cout << "a += 10 => a = " << a << endl;
    b += 5;  
    cout << "b += 5 => b = " << b << endl;
    cout << "\n2. Using -= operator:" << endl;
    a -= 7;  
    cout << "a -= 7 => a = " << a << endl;
    b -= 3;  
    cout << "b -= 3 => b = " << b << endl;
    cout << "\n3. Using *= operator:" << endl;
    a *= 2;   
    cout << "a *= 2 => a = " << a << endl;
    cout << "\n4. Using /= operator:" << endl;
    b /= 2;   
    cout << "b /= 2 => b = " << b << endl;
    cout << "\n5. Using %= operator:" << endl;
    a %= 5; 
    cout << "a %= 5 => a = " << a << endl;
    cout << "\nFinal values: a = " << a << ", b = " << b << endl;
    return 0;
}