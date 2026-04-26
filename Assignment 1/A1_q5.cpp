#include <iostream>
#include <iomanip>  // For setw
using namespace std;
int main() {
    cout << "\n1. Using \\n (newline):" << endl;
    cout << "First Line\nSecond Line\nThird Line" << endl;
    cout << "\n2. Using \\t (tab):" << endl;
    cout << "Name:\tJohn\tAge:\t25" << endl;
    cout << "City:\tDelhi\tCountry:\tIndia" << endl;
    cout << "\n3. Using \\b (backspace):" << endl;
    cout << "Helllo\b World" << endl;
    cout << "\n4. Using endl:" << endl;
    cout << "First line" << endl;
    cout << "Second line" << endl;
    cout << "Third line" << endl;
    cout << "\n5. Using setw (set width):" << endl;
    cout << setw(10) << "Name" << setw(10) << "Age" << setw(15) << "City" << endl;
    cout << setw(10) << "Alice" << setw(10) << 22 << setw(15) << "Mumbai" << endl;
    cout << setw(10) << "Bob" << setw(10) << 25 << setw(15) << "Delhi" << endl;
    cout << setw(10) << "Charlie" << setw(10) << 30 << setw(15) << "Bangalore" << endl;
    cout << "\n6. Combining formatters:" << endl;
    cout << "Student Details:\n" << endl;
    cout << setw(15) << "Roll No" << setw(15) << "Name" << setw(10) << "Marks" << endl;
    cout << setw(15) << 101 << setw(15) << "John" << setw(10) << 85 << endl;
    cout << setw(15) << 102 << setw(15) << "Sarah" << setw(10) << 92 << endl;
    return 0;
}
