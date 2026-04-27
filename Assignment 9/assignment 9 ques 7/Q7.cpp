#include <iostream>
using namespace std;
template <class T>
class Queue
{
T arr[50];
int front, rear;
public:
Queue()
{
front = rear = -1;
}
void enqueue(T value)
{
if(rear == 49)
cout << "Overflow\n";
else
{
if(front == -1)
front = 0;
arr[++rear] = value;
}
}
void dequeue()
{
if(front == -1 || front > rear)
cout << "Underflow\n";
else
front++;
}
void display()
{
for(int i = front; i <= rear; i++)
cout << arr[i] << " ";
cout << endl;
}
};
int main()
{
Queue<int> q;
int n, x;
cout << "Enter number of elements: ";
cin >> n;
for(int i = 0; i < n; i++)
{
cin >> x;
q.enqueue(x);
}
cout << "Queue: ";
q.display();
q.dequeue();
cout << "After dequeue: ";
q.display();
return 0;
}