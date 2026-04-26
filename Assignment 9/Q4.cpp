#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream source("source.txt");
    if (!source) {
        cout << "Error: source.txt not found." << endl;
        return 1;
    }
    ofstream dest("dest.txt");
    char ch;
    while (source.get(ch)) {
        dest.put(ch);
    }
    source.close();
    dest.close();
    cout << "File copied successfully from source.txt to dest.txt" << endl;
    ifstream check("dest.txt");
    cout << "\nContent of dest.txt:" << endl;
    while (check.get(ch)) {
        cout << ch;
    }
    check.close();
    return 0;
}