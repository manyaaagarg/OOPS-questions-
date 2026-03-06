// Question 1: Write a simple base class, then a derived class and use objects of both of 
// them in the main function. It will be a simple illustration of inheritance.
#include<iostream>
#include <string>
using namespace std;
// Base class
class Animal {
protected:
    string name;
    int age;
public:
    // Constructor
    Animal(string n, int a) : name(n), age(a) {
        cout << "Animal constructor called" << endl;
    }
    // Member function
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " years" << endl;
    }
    void makeSound() {
        cout << "Some generic animal sound" << endl;
    }
};
// Derived class
class Dog : public Animal {
private:
    string breed;
public:
    // Constructor
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {
        cout << "Dog constructor called" << endl;
    }
    // Override base class method
    void makeSound() {
        cout << name << " says: Woof! Woof!" << endl;
    }
    // Additional method specific to Dog
    void displayDogInfo() {
        displayInfo();
        cout << "Breed: " << breed << endl;
    }
};
int main() {
    cout << "=== Creating Base Class Object ===" << endl;
    Animal animal1("Generic Animal", 5);
    animal1.displayInfo();
    animal1.makeSound();
    cout << "\n=== Creating Derived Class Object ===" << endl;
    Dog dog1("Buddy", 3, "Golden Retriever");
    dog1.displayDogInfo();
    dog1.makeSound();
    return 0;
}