#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ofstream numFile("NUM.TXT");
    for(int i = 1; i <= 200; i++) {
        numFile << i << " ";
    }
    numFile.close();
    ifstream inFile("NUM.TXT");   
    ofstream evenFile("EVEN.TXT");
    ofstream oddFile("ODD.TXT");
    int num;
    while(inFile >> num) {
        if(num % 2 == 0)
            evenFile << num << " ";
        else
            oddFile << num << " ";
    }
    inFile.close();
    evenFile.close();
    oddFile.close();
    int choice;
    cout << "Enter 1 for EVEN file\n";
    cout << "Enter 2 for ODD file\n";
    cin >> choice;
    if(choice == 1) {
        ifstream evenRead("EVEN.TXT");
        ofstream result("RESULT.TXT");
        while(evenRead >> num) {
            result << num << " ";
        }
        evenRead.close();
        result.close();
    }
    else if(choice == 2) {
        ifstream oddRead("ODD.TXT");
        ofstream result("RESULT.TXT");
        while(oddRead >> num) {
            result << num << " ";
        }
        oddRead.close();
        result.close();
    }
    return 0;
}