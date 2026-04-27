#include <iostream>
#include <string>
using namespace std;
class LibraryUser {
protected:
    string name;
    int userId;
    string contactNumber;
    string email;
    int booksBorrowed;
public:
    LibraryUser() {
        name = "Unknown";
        userId = 0;
        contactNumber = "N/A";
        email = "N/A";
        booksBorrowed = 0;
        cout << "LibraryUser default constructor called" << endl;
    }
    LibraryUser(string n, int id, string contact, string mail) {
        name = n;
        userId = id;
        contactNumber = contact;
        email = mail;
        booksBorrowed = 0;
        cout << "LibraryUser created: " << name << " (ID: " << userId << ")" << endl;
    }
    void displayUserInfo() {
        cout << "Name: " << name << endl;
        cout << "User ID: " << userId << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "Email: " << email << endl;
        cout << "Books Borrowed: " << booksBorrowed << endl;
    }
    void borrowBook() {
        booksBorrowed++;
        cout << name << " borrowed a book. Total books: " << booksBorrowed << endl;
    }
    void returnBook() {
        if (booksBorrowed > 0) {
            booksBorrowed--;
            cout << name << " returned a book. Remaining books: " << booksBorrowed << endl;
        } else {
            cout << name << " has no books to return." << endl;
        }
    }
    string getName() const { return name; }
    int getUserId() const { return userId; }
    int getBooksBorrowed() const { return booksBorrowed; }
    virtual ~LibraryUser() {
        cout << "LibraryUser destroyed: " << name << endl;
    }};
class Student : public LibraryUser {
private:
    string gradeLevel;
    string major;
    string enrollmentYear;
    int maxBooksAllowed;
public:
    Student(string n, int id, string contact, string mail, string grade, string maj, string year) 
        : LibraryUser(n, id, contact, mail) {
        gradeLevel = grade;
        major = maj;
        enrollmentYear = year;
        maxBooksAllowed = 5; 
        cout << "Student account created - Grade: " << gradeLevel << endl;
    }
    void borrowBook() {
        if (booksBorrowed < maxBooksAllowed) {
            LibraryUser::borrowBook();
        } else {
            cout << "Cannot borrow more books! Student limit: " << maxBooksAllowed << endl;
        }}
    void displayStudentInfo() {
        displayUserInfo();
        cout << "Grade Level: " << gradeLevel << endl;
        cout << "Major: " << major << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "Max Books Allowed: " << maxBooksAllowed << endl;
    }
    bool canBorrowMore() {
        return booksBorrowed < maxBooksAllowed;
    }
    string getGradeLevel() const { return gradeLevel; }
    string getMajor() const { return major; }
    ~Student() {
        cout << "Student account closed: " << name << " (" << gradeLevel << ")" << endl;
    }};
class Teacher : public LibraryUser {
private:
    string department;
 string designation;
    int yearsOfExperience;
int maxBooksAllowed;
 bool hasResearchAccess;
public:
    Teacher(string n, int id, string contact, string mail, string dept, string desig, int exp) 
        : LibraryUser(n, id, contact, mail) {
        department = dept;
        designation = desig;
        yearsOfExperience = exp;
        maxBooksAllowed = 10; 
        hasResearchAccess = true;
        cout << "Teacher account created - Department: " << department << endl;
    }
    void borrowBook() {
        if (booksBorrowed < maxBooksAllowed) {
            LibraryUser::borrowBook();
        } else {
            cout << "Cannot borrow more books! Teacher limit: " << maxBooksAllowed << endl;
        }
    }
    void displayTeacherInfo() {
        displayUserInfo();
        cout << "Department: " << department << endl;
        cout << "Designation: " << designation << endl;
        cout << "Years of Experience: " << yearsOfExperience << endl;
        cout << "Max Books Allowed: " << maxBooksAllowed << endl;
        cout << "Research Access: " << (hasResearchAccess ? "Yes" : "No") << endl;
    }
    void requestResearchMaterial(string materialName) {
    if (hasResearchAccess) {
        cout << name << " requested research material: " << materialName << endl;
        cout << "Request approved." << endl;
} else {
cout << "No research access available." << endl;}}
    bool canBorrowMore() {
        return booksBorrowed < maxBooksAllowed;
    }
    string getDepartment() const { return department; }
    string getDesignation() const { return designation; }
    ~Teacher() {
        cout << "Teacher account closed: " << name << " (" << department << ")" << endl;
    }};
void displayLibraryStats(Student students[], int numStudents, Teacher teachers[], int numTeachers) {
    int totalStudentBooks = 0;
    int totalTeacherBooks = 0;
    for (int i = 0; i < numStudents; i++) {
        totalStudentBooks += students[i].getBooksBorrowed();
    }
    for (int i = 0; i < numTeachers; i++) {
        totalTeacherBooks += teachers[i].getBooksBorrowed();
    }
    cout << "Total Students: " << numStudents << endl;
    cout << "Total Teachers: " << numTeachers << endl;
    cout << "Books borrowed by Students: " << totalStudentBooks << endl;
    cout << "Books borrowed by Teachers: " << totalTeacherBooks << endl;
    cout << "Total Books in Circulation: " << (totalStudentBooks + totalTeacherBooks) << endl;
}
int main() {
    cout << "\n--- Creating Student Accounts ---" << endl;
    Student student1("Alice Johnson", 1001, "555-0101", "alice@university.edu", 
    "Sophomore", "Computer Science", "2023");
    Student student2("Bob Smith", 1002, "555-0102", "bob@university.edu", 
    "Senior", "Mathematics", "2021");
    Student student3("Carol White", 1003, "555-0103", "carol@university.edu", 
    "Freshman", "Physics", "2024");
    cout << "\n--- Creating Teacher Accounts ---" << endl;
    Teacher teacher1("Dr. David Brown", 2001, "555-0201", "david.brown@university.edu", 
    "Computer Science", "Professor", 15);
    Teacher teacher2("Dr. Emma Davis", 2002, "555-0202", "emma.davis@university.edu", 
    "Mathematics", "Associate Professor", 8);
    student1.displayStudentInfo();
    student2.displayStudentInfo();
    teacher1.displayTeacherInfo();
    student1.borrowBook();
    student1.borrowBook();
    student1.borrowBook();
    student2.borrowBook();
    student2.borrowBook();
    teacher1.borrowBook();
    teacher1.borrowBook();
    teacher1.borrowBook();
    teacher1.borrowBook();
    for (int i = 0; i < 5; i++) {
        student1.borrowBook(); 
    }
    cout << "\n--- Returning Books ---" << endl;
    student1.returnBook();
    student1.returnBook();
    teacher1.requestResearchMaterial("Advanced Algorithms Journal");
    student1.displayStudentInfo();
    teacher1.displayTeacherInfo();
    Student studentArray[] = {student1, student2, student3};
    Teacher teacherArray[] = {teacher1, teacher2};
    displayLibraryStats(studentArray, 3, teacherArray, 2);
    return 0;
}