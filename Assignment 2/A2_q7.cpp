#include <iostream>
using namespace std;
namespace Student {
int rollNo = 401;
string name = "MANYA";
void display() {
cout << "Student Namespace:" << endl;
cout << "Roll No: " << rollNo << endl;
cout << "Name: " << name << endl;
}
void updateDetails(int roll, string n) {
rollNo = roll;
name = n;
}}
namespace Employee {
int rollNo = 501;  
string name = "Bob";  
 void display() {  
cout << "Employee Namespace:" << endl;
cout << "Employee ID: " << rollNo << endl;
cout<< "Name: " << name << endl;
 }
void updateDetails(int id, string n) { 
 rollNo = id;
 name = n;
    }}
namespace Product {
int rollNo = 1001;
string name = "Laptop";
double price = 45000.50;
void display() {
 cout << "Product Namespace:" << endl;
 cout << "Product ID: " << rollNo << endl;
cout << "Product Name: " << name << endl;
cout << "Price: Rs. " << price << endl;}
 void updatePrice(double newPrice) {
price = newPrice;
cout << "Price updated to Rs. " << price << endl;}}
namespace University {
 namespace Department {
string deptName = "Computer Science";
int studentCount = 150;
void displayInfo() {
cout << "Department: " << deptName << endl;
cout << "Total Students: " << studentCount << endl;
}}}
int main() {
    cout << "Demonstrating Namespace in C++" << endl;
    cout << "\nMethod 1: Using :: operator" << endl;
    Student::display();
    cout << endl;
    Employee::display();
    cout << endl;
    Product::display();
    cout << "\n Accessing Same Variable Names" << endl;
    cout << "Student Roll No: " << Student::rollNo << endl;
    cout << "Employee Roll No (ID): " << Employee::rollNo << endl;
    cout << "Product Roll No (ID): " << Product::rollNo << endl;
    cout << "\nUpdating Details in Different Namespaces" << endl;
    Student::updateDetails(102, "Charlie");
    Employee::updateDetails(502, "David");
    cout << "\nAfter update:" << endl;
    Student::display();
    cout << endl;
    Employee::display();
    cout << "\nMethod 2: Using 'using' directive" << endl;
    {
 using namespace Product;
cout << "Product Name (using directive): " << name << endl;
updatePrice(48000.00);
    }
    cout << "\nMethod 3: Using declaration" << endl;
    using Student::name;  
    cout << "Student name: " << name << endl;
    cout << "\nNested Namespace" << endl;
    University::Department::displayInfo();
    cout << "\nNamespace Aliasing" << endl;
    namespace UD = University::Department;
    cout << "Department (using alias): " << UD::deptName << endl;
    cout << "\nUsing Multiple Namespaces Together" << endl;
    cout << "Student: "<< Student::name << endl;
    cout << "Employee: "<< Employee::name << endl;
    cout << "Product: "<< Product::name << endl;
    return 0;
}