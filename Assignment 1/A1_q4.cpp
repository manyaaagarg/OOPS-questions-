#include <iostream>
using namespace std;

int main() {
    float celsius, fahrenheit;
    
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;
    fahrenheit = (9.0 * celsius / 5.0) + 32;
    cout << celsius << " degree Celsius = " << fahrenheit << " degree Fahrenheit" << endl;
    
    return 0;
}