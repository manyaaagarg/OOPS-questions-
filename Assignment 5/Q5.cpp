#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int age;
public:
    Person() {
        name = "Unknown";
        age = 0;
        cout << "Person default constructor called" << endl;
    }
    Person(string n, int a) : name(n), age(a) {
        cout << "Person parameterized constructor called for: " << name << endl;
    }
    ~Person() {
        cout << "Person destructor called for: " << name << endl;
    }
    void displayPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }};
class Employee : public Person {
private:
    int employeeId;
    string department;
public:
    Employee() : Person() {
        employeeId = 0;
        department = "Not Assigned";
        cout << "Employee default constructor called" << endl;
    }
    Employee(string n, int a, int id, string dept) : Person(n, a) {
employeeId = id;
department = dept;
 cout << "Employee parameterized constructor called for ID: " << employeeId << endl;
    }
    ~Employee() {
 cout << "Employee destructor called for ID: " << employeeId << endl;
    }
    void displayEmployee() {
        displayPerson();
        cout << "Employee ID: " << employeeId << endl;
        cout << "Department: " << department << endl;
}};
class Manager : public Employee {
private:
int teamSize;
public:
Manager() : Employee() {
teamSize = 0;
cout << "Manager default constructor called" << endl;
 }
Manager(string n, int a, int id, string dept, int team) 
: Employee(n, a, id, dept) {
teamSize = team;
cout << "Manager parameterized constructor called, Team Size: " << teamSize << endl;
    }
    ~Manager() {
        cout << "Manager destructor called for team size: " << teamSize << endl;
    }
    void displayManager() {
        displayEmployee();
        cout << "Team Size: " << teamSize << endl;
    }};
int main() {
    cout << "--- Creating Employee Object ---" << endl;
    Employee emp1("Alice Smith", 30, 1001, "IT");
    cout << "\n--- Displaying Employee Information ---" << endl;
    emp1.displayEmployee();
    cout << "\n\n--- Creating Manager Object ---" << endl;
    Manager mgr1("Bob Johnson", 40, 2001, "Sales", 10);
    cout << "\n--- Displaying Manager Information ---" << endl;
    mgr1.displayManager();
    cout << "Objects will be destroyed in reverse order of creation" << endl;
    cout << "Destructors are called automatically when objects go out of scope\n" << endl;
    {
        cout << "--- Creating objects in a block ---" << endl;
        Person p1("Charlie", 25);
        Employee e1("Diana", 28, 3001, "HR");
        cout << "\n--- Exiting block, destructors will be called now ---" << endl;
    }
    return 0;
}