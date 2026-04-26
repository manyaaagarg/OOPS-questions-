#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
void countAlphabets() {
    ifstream file("NOTES.TXT");
    if (!file) {
        cout << "Error: Could not open NOTES.TXT" << endl;
        return;
    }
    char ch;
    int count = 0;
    while (file.get(ch)) {
        if (isalpha(ch)) {
            count++;
        }
    }
    file.close();
    cout << "Number of alphabets: " << count << endl;
}
int main() {
    countAlphabets();
    return 0;
}