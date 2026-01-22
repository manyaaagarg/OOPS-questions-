#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int rollNo;
    string degree;
    string hostel;
    float cgpa;

public:
    void addDetails()
    {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Roll No: ";
        cin >> rollNo;

        cout << "Enter Degree: ";
        cin >> degree;

        cout << "Enter Hostel Name: ";
        cin >> hostel;

        cout << "Enter Current CGPA: ";
        cin >> cgpa;
    }

    void updateCGPA()
    {
        cout << "Enter Updated CGPA: ";
        cin >> cgpa;
    }

    void updateHostel()
    {
        cout << "Enter New Hostel Name: ";
        cin >> hostel;
    }

    void displayDetails()
    {
        cout << "\nStudent Details\n";
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Degree: " << degree << endl;
        cout << "Hostel: " << hostel << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

int main()
{
    Student s;

    s.addDetails();
    s.displayDetails();
    s.updateCGPA();
    s.updateHostel();
    s.displayDetails();

    return 0;
}
