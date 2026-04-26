#include <iostream>
using namespace std;
class Number {
private:
int value;
public:
Number(int v = 0) {
value = v;
cout << "Constructor called for value: " << value << endl;
}
Number(const Number &obj) {
value = obj.value;
cout << "Copy constructor called for value: " << value << endl;
}
~Number() {
cout << "Destructor called for value: " << value << endl;
}
void display() const {
cout << "Value: " << value << endl;
}
int getValue() const {
return value;
}
void setValue(int v) {
value = v;
}};
Number addNumbers(const Number &n1, const Number &n2) {
int sum = n1.getValue() + n2.getValue();
Number result(sum);
return result;
}
void increment(Number &n) {
int newValue = n.getValue() + 1;
n.setValue(newValue);
cout << "Incremented inside function" << endl;
}
void modifyByValue(Number n) {
n.setValue(999);
cout << "Modified to 999 inside function (copy)" << endl;
}
void modifyByReference(Number &n) {
n.setValue(999);
cout << "Modified to 999 inside function (reference)" << endl;
}
int main() {
cout << "\nTEST 1: Addition (pass by reference)" << endl;
Number num1(10);
Number num2(20);
cout << "\nCalling addNumbers with reference:" << endl;
Number sum = addNumbers(num1, num2);
cout << "\nResult:" << endl;
sum.display();
cout << "\nTEST 2: Increment (pass by reference) " << endl;
Number num3(50);
cout << "\nBefore increment:" << endl;
num3.display();
increment(num3); 
cout << "\nAfter increment:" << endl;
num3.display();
cout << "\n TEST 3: Value vs Reference Comparison " << endl;
Number num4(100);
cout << "\nOriginal value:" << endl;
num4.display();
cout << "\nTrying to modify by VALUE:" << endl;
modifyByValue(num4);
cout << "After modifyByValue:" << endl;
num4.display();
cout << "\nTrying to modify by REFERENCE:" << endl;
modifyByReference(num4);
cout << "After modifyByReference:" << endl;
num4.display();
return 0;
}