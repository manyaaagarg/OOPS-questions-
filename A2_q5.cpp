#include <iostream>
using namespace std;

class Complex
{
    float real;
    float imaginary;

public:
    void setComplex(float r, float i)
    {
        real = r;
        imaginary = i;
    }

    void displayComplex()
    {
        cout << real << " + " << imaginary << "i" << endl;
    }
    
    Complex addComplex(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imaginary = imaginary + c.imaginary;
        return temp;
    }
};

int main()
{
    Complex c1, c2, sum;
    float r, i;

    cout << "Enter real and imaginary part of first complex number: ";
    cin >> r >> i;
    c1.setComplex(r, i);

    cout << "Enter real and imaginary part of second complex number: ";
    cin >> r >> i;
    c2.setComplex(r, i);

    sum = c1.addComplex(c2);

    cout << "\nFirst Complex Number: ";
    c1.displayComplex();

    cout << "Second Complex Number: ";
    c2.displayComplex();

    cout << "Sum of Complex Numbers: ";
    sum.displayComplex();

    return 0;
}
