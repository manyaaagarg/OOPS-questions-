#include <iostream>
using namespace std;
template <class T>
class Array
{
T arr[50];
int n;
public:
void input()
{
cout << "Enter size: ";
cin >> n;

for(int i = 0; i < n; i++)
cin >> arr[i];
}
void display()
{
cout << "Elements: ";
for(int i = 0; i < n; i++)
cout << arr[i] << " ";
}
};
int main()
{
Array<int> a;
a.input();
a.display();
return 0;
}