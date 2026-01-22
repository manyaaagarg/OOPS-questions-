#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int rollNo;
    float cgpa;

    void validateCGPA()
    {
        if (cgpa < 0 || cgpa > 10)
            cout << "Invalid CGPA entered!" << endl;
        else
            cout << "CGPA is valid." << endl;
    }

public:
    void addDetails()
    {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Roll No: ";
        cin >> rollNo;

        cout << "Enter CGPA: ";
        cin >> cgpa;

        validateCGPA();
    }

    void displayDetails()
    {
        cout << "\nName: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

int main()
{
    Student s;
    s.addDetails();
    s.displayDetails();

    return 0;
}
