#include<iostream>
using namespace std;
template<class T>
T findMax(T arr[], int n)
{
    T max = arr[0]; 
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[50];
    cout << "Enter " << n << " integer elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Maximum element = " << findMax(arr, n) << endl;
    return 0;
}