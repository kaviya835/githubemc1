#include <iostream>
using namespace std;

// Function declarations (prototypes)
int add(int, int);
int subtract(int, int);
int multiply(int, int);
double divide(int, int);

// Function to perform operations
void performOperation(int a, int b, int choice) {
    switch (choice) {
        case 1: cout << "Sum: " << add(a, b) << endl; break;
        case 2: cout << "Difference: " << subtract(a, b) << endl; break;
        case 3: cout << "Product: " << multiply(a, b) << endl; break;
        case 4: 
            if (b != 0) 
                cout << "Quotient: " << divide(a, b) << endl; 
            else 
                cout << "Error: Division by zero is not allowed." << endl;
            break;
        default: cout << "Invalid choice!" << endl;
    }
}

// Function definitions
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
double divide(int a, int b) { return (double)a / b; }

int main() {
    int num1, num2, choice;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Choose operation:\n";
    cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
    cin >> choice;

    performOperation(num1, num2, choice);

    return 0;
}

