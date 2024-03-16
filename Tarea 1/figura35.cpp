//fig 35

// Code B
// User type to simplify the declaration
#include <iostream>
using namespace std;

typedef double (*lpfnOperation)(double, double);


double Addition(double a, double b) { return a + b; }
double Subtraction(double a, double b) { return a - b; }
double Multiplication(double a, double b) { return a * b; }
double Division(double a, double b) {
    if (b != 0) return a / b;
    else {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
}

lpfnOperation vpf[4] = { &Addition, &Subtraction, &Multiplication, &Division };

int main() {
    double a, b, c;
    int opt;

    cout << "Ingrese los operandos: ";
    cin >> a >> b;

    cout << "Escoja la operación (0: Addition, 1: Subtraction, 2: Multiplication, 3: Division): ";
    cin >> opt;

    c = vpf[opt](a, b);

    cout << "Result: " << c << endl;

    return 0;
}
