#include <iostream>
using namespace std;
template <class T1, class T2>
class Pair
{
T1 a;
T2 b;
public:
void input()
{
cin >> a >> b;
}
void display()
{
cout << "Values are: " << a << " " << b;
}
};
int main()
{
Pair<int, float> p;
cout << "Enter two values: ";
p.input();
p.display();
return 0;
}