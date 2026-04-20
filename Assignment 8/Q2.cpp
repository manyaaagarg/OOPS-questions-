#include<iostream>
using namespace std;
// template function to find minimum element
template<class T>
T findMin(T arr[], int n)
{
    T min = arr[0];   // assume first element is minimum
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
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
    cout << "Minimum element = " << findMin(arr, n) << endl;
    return 0;
}
