#include <iostream>
int value = 100;
class ScopeDemo {
private:
    int value;
    static int staticCount; 
    
public:
    ScopeDemo(int v);
    void displayValue();
    void compareValues(int value);
    static void displayStaticCount();
    static void incrementCount();
};

int ScopeDemo::staticCount = 0;
ScopeDemo::ScopeDemo(int v) {
    value = v;
    staticCount++;
}
void ScopeDemo::displayValue() {
    std::cout << "Member variable value: " << value << std::endl;
}
void ScopeDemo::compareValues(int value) {
    std::cout << "\n=== Accessing Global vs Local Variables ===" << std::endl;
    std::cout << "Local parameter value: " << value << std::endl;
    std::cout << "Member variable value: " << this->value << std::endl;
    std::cout << "Global variable value: " << ::value << std::endl;
}
void ScopeDemo::displayStaticCount() {
    std::cout << "Static count (total objects created): " << staticCount << std::endl;
}

void ScopeDemo::incrementCount() {
    staticCount++;
}

int main() {
    std::cout << "=== Demonstrating Scope Resolution Operator :: ===" << std::endl;
    std::cout << "\n(a) Class functions defined outside using ::" << std::endl;
    ScopeDemo obj1(50);
    obj1.displayValue();
    
    std::cout << "\n(b) Global vs Local variable access:" << std::endl;
    int value = 200; 
    std::cout << "Local main() variable: " << value << std::endl;
    std::cout << "Global variable using :: " << ::value << std::endl;
    
    obj1.compareValues(300);  
    std::cout << "\n(c) Static variable access using ::" << std::endl;
    ScopeDemo::displayStaticCount(); 
    
    ScopeDemo obj2(75);
    ScopeDemo obj3(90);
    
    std::cout << "After creating 2 more objects:" << std::endl;
    ScopeDemo::displayStaticCount();
    std::cout << "\n(d) Using std:: scope resolution for cin/cout:" << std::endl;
    std::cout << "This entire program uses std::cout with :: operator" << std::endl;
    
    int input;
    std::cout << "Enter a number: ";
    std::cin >> input;
    std::cout << "You entered: " << input << std::endl;
    std::cout << "\n=== Additional Examples ===" << std::endl;
    std::cout << "std::endl is also using scope resolution!" << std::endl;
    
    return 0;
}