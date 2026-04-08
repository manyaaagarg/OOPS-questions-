#include<iostream>
using namespace std;
// template function to search an element in array
template<class T>
void linearSearch(T arr[], int n, T key)
{
    int i;
    int found = 0;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            cout << "Element found at position " << i+1 << endl;
            found = 1;
            break;
        }
    }
    if(found == 0)
    {
        cout << "Element not found." << endl;
    }
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[50];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    linearSearch(arr, n, key);
    return 0;
}