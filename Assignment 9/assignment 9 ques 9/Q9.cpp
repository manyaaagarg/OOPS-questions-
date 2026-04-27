#include <iostream>
using namespace std;
template <class T>
class Calculator
{
T a, b;
public:
void input()
{
cin >> a >> b;
}
void show()
{
cout << "Add = " << a + b << endl;
cout << "Sub = " << a - b << endl;
cout << "Mul = " << a * b << endl;
cout << "Div = " << a / b << endl;
}
};
int main()
{
Calculator<int> c;
cout << "Enter two numbers: ";
c.input();
c.show();
return 0;
}