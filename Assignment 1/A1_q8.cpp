#include <iostream>
using namespace std;
int main() {
    int lateDays;
    float fine;
    cout << "Enter number of days late: ";
    cin >> lateDays;
    if (lateDays <= 0) {
        cout << "Book returned on time. No fine!" << endl; }
    else if (lateDays > 30) {
        cout << "Your membership has been CANCELLED!" << endl;
        cout << "Book returned " << lateDays << " days late (more than 30 days)." << endl;}
    else if (lateDays >= 1 && lateDays <= 5) {
        fine = lateDays * 0.50;  
        cout << "Fine for " << lateDays << " day(s): Rs. " << fine << endl;}
    else if (lateDays >= 6 && lateDays <= 10) {
        fine = lateDays * 1.00;  
        cout << "Fine for " << lateDays << " day(s): Rs. " << fine << endl; }
    else {  
        fine = lateDays * 5.00;  
        cout << "Fine for " << lateDays << " day(s): Rs. "  << fine << endl;}
    return 0;
}