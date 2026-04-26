#include <iostream>
#include <fstream>
using namespace std;
class Student {
public:
    int roll;
    char name[50];
    float marks;
    void getData() {
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }
    void showData() {
        cout << "Roll No: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};
int main() {
    Student s;
    s.getData();
    ofstream out("student.dat", ios::binary);
    out.write((char*)&s, sizeof(s));
    out.close();
    cout << "\nData written to file successfully." << endl;
    Student s2;
    ifstream in("student.dat", ios::binary);
    in.read((char*)&s2, sizeof(s2));
    in.close();
    cout << "\nData read from file:" << endl;
    s2.showData();
    return 0;
}