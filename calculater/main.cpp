#include <iostream>
#include <cmath>
using namespace std;

int main() {
    char op;
    float num1, num2;

    cout << "Enter operator (+, -, *, /, s, c, t, x^y, sqrt): ";
    cin >> op;

    switch(op) {
        case '+':
        case '-':
        case '*':
        case '/':
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            break;

        case 's':
        case 'c':
        case 't':
            cout << "Enter a number (in radians): ";
            cin >> num1;
            break;

        case '^':
            cout << "Enter base and exponent: ";
            cin >> num1 >> num2;
            break;

        case 'x':
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            break;

        case 'q':
            cout << "Enter a number: ";
            cin >> num1;
            break;

        default:
            cout << "Error! Invalid operator.";
            return 1;
    }

    switch(op) {
        case '+':
            cout << "Result: " << num1 + num2;
            break;

        case '-':
            cout << "Result: " << num1 - num2;
            break;

        case '*':
            cout << "Result: " << num1 * num2;
            break;

        case '/':
            if (num2 != 0)
                cout << "Result: " << num1 / num2;
            else
                cout << "Error! Division by zero.";
            break;

        case 's':
            cout << "Result: " << sin(num1);
            break;

        case 'c':
            cout << "Result: " << cos(num1);
            break;

        case 't':
            cout << "Result: " << tan(num1);
            break;

        case '^':
            cout << "Result: " << pow(num1, num2);
            break;

        case 'x':
            cout << "Result: " << num1 * num2;
            break;

        case 'q':
            cout << "Result: " << sqrt(num1);
            break;

        default:
            cout << "Error! Invalid operator.";
            return 1;
    }

    return 0;
}
