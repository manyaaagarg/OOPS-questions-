#include <iostream>
#include <string>
using namespace std;
class Base {
private:
int privateData;
protected:
int protectedData;
public:
int publicData;
    Base() {
        privateData = 10;
        protectedData = 20;
        publicData = 30;
    }
void showBaseData() {
        cout << "Private Data: " << privateData << endl;
        cout << "Protected Data: " << protectedData << endl;
        cout << "Public Data: " << publicData << endl;
    }};
class PublicDerived : public Base {
public:
    void accessBaseMembers() {
        cout << "Protected Data (from base): " << protectedData << endl;
        protectedData = 25; 
        cout << "Public Data (from base): " << publicData << endl;
        publicData = 35; 
    }};
class ProtectedDerived : protected Base {
public:
    void accessBaseMembers() {
        cout << "Protected Data (from base): " << protectedData << endl;
        protectedData = 27;
        cout << "Public Data (from base, now protected): " << publicData << endl;
        publicData = 37;
    }};
class PrivateDerived : private Base {
public:
    void accessBaseMembers() {
        cout << "Protected Data (from base, now private): " << protectedData << endl;
        protectedData = 29;  
        cout << "Public Data (from base, now private): " << publicData << endl;
        publicData = 39; 
    }};
int main() {
    cout << "\n--- Testing Public Inheritance ---" << endl;
    PublicDerived pubObj;
    pubObj.accessBaseMembers();
    pubObj.publicData = 100; 
    cout << "Accessing publicData from outside: " << pubObj.publicData << endl;
    cout << "\n--- Testing Protected Inheritance ---" << endl;
    ProtectedDerived protObj;
    protObj.accessBaseMembers();
    cout << "\n--- Testing Private Inheritance ---" << endl;
    PrivateDerived privObj;
    privObj.accessBaseMembers();
    return 0;
}