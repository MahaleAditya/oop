#include<iostream>
using namespace std;

// Define a class named 'complex'
class complex {
    int r; // Real part
    int i; // Imaginary part

public:
    // Default constructor to initialize real and imaginary parts to 0
    complex() {
        r = 0;
        i = 0;
    }

    // Overloaded addition operator
    complex operator + (complex);

    // Overloaded subtraction operator
    complex operator - (complex);

    // Overloaded multiplication operator
    complex operator * (complex);

    // Friend function for input stream (cin)
    friend istream & operator>>(istream &input, complex &t);

    // Friend function for output stream (cout)
    friend ostream & operator<<(ostream &output, const complex &t);
};

// Friend function to overload input stream (cin) for 'complex' class
istream & operator>>(istream &input, complex &t) {
    cout << "Enter the real part: ";
    input >> t.r;
    cout << "Enter the imaginary part: ";
    input >> t.i;
    return input;
}

// Friend function to overload output stream (cout) for 'complex' class
ostream & operator<<(ostream &output, const complex &t) {
    output << t.r << "+" << t.i << "i";
    return output;
}

// Overloaded addition operator for 'complex' class
complex complex::operator+(complex c) {
    complex c1;
    cout << "Addition of complex numbers:\n";
    c1.r = r + c.r;
    c1.i = i + c.i;
    return c1;
}

// Overloaded subtraction operator for 'complex' class
complex complex::operator-(complex c) {
    complex c2;
    cout << "Subtraction of complex numbers:\n";
    c2.r = r - c.r;
    c2.i = i - c.i;
    return c2;
}

// Overloaded multiplication operator for 'complex' class
complex complex::operator*(complex c) {
    complex c3;
    cout << "Multiplication of complex numbers:\n";
    c3.r = (r * c.r) - (i * c.i);
    c3.i = (i * c.r) + (r * c.i);
    return c3;
}

// Main function
int main() {
    complex a, b, c, d;

    // Display the default complex number 'a'
    cout << "Default complex number a: " << a << endl;

    // Input complex numbers 'b' and 'c' from the user
    cin >> b >> c;

    // Display the entered complex numbers 'b' and 'c'
    cout << "Entered complex numbers b and c: " << b << " and " << c << endl;

    // Perform addition, subtraction, and multiplication of complex numbers 'b' and 'c'
    d = b + c;
    cout << "Result of addition (b + c): " << d << endl;

    d = b - c;
    cout << "Result of subtraction (b - c): " << d << endl;

    d = b * c;
    cout << "Result of multiplication (b * c): " << d << endl;

    return 0;
}
