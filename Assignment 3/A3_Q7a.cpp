#include <iostream>
using namespace std;
class Number {
private:
int value;
public:
Number(int v = 0) {
value = v;
cout << "Constructor called for value: " << value << endl; }
Number(const Number &obj) {
value = obj.value;
cout << "Copy constructor called for value: " << value << endl;
 }
~Number() {
cout << "Destructor called for value: " << value << endl;
}
void display() {
 cout << "Value: " << value << endl;
}
int getValue() {
return value;}};
Number addNumbers(Number n1, Number n2) {
    int sum = n1.getValue() + n2.getValue();
    Number result(sum);
}
Number multiply(Number n, int factor) {
    int product = n.getValue() * factor;
    Number result(product);
    return result;
}
int main() {
cout << "\n1. Creating objects:" << endl;
Number num1(10);
Number num2(20);
cout << "\n2. Calling addNumbers (pass by value):" << endl;
Number sum = addNumbers(num1, num2);
cout << "\n3. Result of addition:" << endl;
sum.display();
cout << "\n4. Original objects unchanged:" << endl;
num1.display();
num2.display();
cout << "\n5. Calling multiply:" << endl;
Number product = multiply(num1, 3);
cout << "\n6. Result of multiplication:" << endl;
product.display();
cout << "\n7. Program ending (destructors will be called):" << endl;
return 0;
}