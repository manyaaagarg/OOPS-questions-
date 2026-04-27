#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Book {
protected:
    string title;
    string author;
    double price;
public:
    Book() {
        title = "Unknown";
        author = "Unknown";
        price = 0.0;
    }
    Book(string t, string a, double p) : title(t), author(a), price(p) {
        cout << "Book object created: " << title << endl;
    }
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setPrice(double p) { price = p; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    double getPrice() const { return price; }
    void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << fixed << setprecision(2);
        cout << "Price: $" << price << endl;
    }
    virtual ~Book() {
        cout << "Book object destroyed: " << title << endl;
    }};
class Textbook : public Book {
private:
string subject;
public:
    Textbook() : Book() {
        subject = "General";
    }
Textbook(string t, string a, double p, string s) : Book(t, a, p), subject(s) {
cout << "Textbook object created with subject: " << subject << endl;
    }
    void setSubject(string s) { subject = s; }
    string getSubject() const { return subject; }
    void displayInfo() {
        Book::displayInfo();
        cout << "Subject: " << subject << endl;
    }
    void displayCategory() {
        cout << "This is an educational textbook for " << subject << endl;
    }
    ~Textbook() {
        cout << "Textbook object destroyed: " << subject << endl;
    }};
int main() {
cout << "\n--- Creating a General Book ---" << endl;
Book book1("The Great Gatsby", "F. Scott Fitzgerald", 12.99);
    cout << "\n--- Displaying General Book Information ---" << endl;
    book1.displayInfo();
    Textbook textbook1("Introduction to C++", "Bjarne Stroustrup", 89.99, "Computer Science");
    Textbook textbook2("Calculus", "James Stewart", 149.99, "Mathematics");
    Textbook textbook3("Physics Fundamentals", "David Halliday", 119.99, "Physics");
    cout << "\n--- Displaying Textbook Information ---" << endl;
    textbook1.displayInfo();
    textbook1.displayCategory();
    textbook2.displayInfo();
    textbook2.displayCategory();
    textbook3.displayInfo();
    textbook3.displayCategory();
    cout << "\n--- Using Base Class Methods on Derived Object ---" << endl;
    cout << "Textbook 1 Author: " << textbook1.getAuthor() << endl;
    cout << "Textbook 1 Price: $" << textbook1.getPrice() << endl;
    cout << "\n--- Modifying Textbook Information ---" << endl;
    textbook1.setPrice(79.99);
    textbook1.setSubject("Advanced C++ Programming");
    cout << "Updated information:" << endl;
    textbook1.displayInfo();
    cout << "\n--- Managing Book Inventory ---" << endl;
    Book* inventory[4];
    inventory[0] = &book1;
    inventory[1] = &textbook1;
    inventory[2] = &textbook2;
    inventory[3] = &textbook3;
    
    double totalValue = 0;
    for (int i = 0; i < 4; i++) {
        totalValue += inventory[i]->getPrice();
    }
    
    cout << fixed << setprecision(2);
    cout << "Total Inventory Value: $" << totalValue << endl;
    return 0;
}