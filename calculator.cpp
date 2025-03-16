#include <bits/stdc++.h>
using namespace std;

int main()
{
    int choice;
    double num1, num2, result;

    while (true)                                                                                 // Loop until user chooses to exit
    {
        cout << "\n-------- SCIENTIFIC CALCULATOR ---------" << endl;
        cout << "Select an operation: " << endl;
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Modulus (%)\n";
        cout << "6. Square Root (√)\n";
        cout << "7. Power (x^y)\n";
        cout << "8. Logarithm (log base 10)\n";
        cout << "9. Sine (sin)\n";
        cout << "10. Cosine (cos)\n";
        cout << "11. Tangent (tan)\n";
        cout << "12. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 12)
        {
            cout << "Exiting the calculator. Goodbye!\n";
            break;
        }

        if (cin.fail())                                                                                     // If user enters non-numeric input
        {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();                                                                                 // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                                            // Ignore wrong input
            continue;
        }

        if (choice >= 1 && choice <= 5)
        {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
        }
        else if (choice >= 6 && choice <= 11)
        {
            cout << "Enter the number: ";
            cin >> num1;
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            result = num1 + num2;
            break;
        case 2:
            result = num1 - num2;
            break;
        case 3:
            result = num1 * num2;
            break;
        case 4:
            if (num2 == 0)
            {
                cout << "ERROR: Division by zero is not allowed!\n";
                continue;
            }
            result = num1 / num2;
            break;
        case 5:
            if (num2 == 0)
            {
                cout << "ERROR: Modulus by zero is not allowed!\n";
                continue;
            }
            result = fmod(num1, num2);                                                              // Corrected modulus for floating-point numbers
            break;
        case 6:
            if (num1 < 0)
            {
                cout << "ERROR: Square root of negative number is not possible!\n";
                continue;
            }
            result = sqrt(num1);
            break;
        case 7:
            cout << "Enter exponent: ";
            cin >> num2;
            result = pow(num1, num2);
            break;
        case 8:
            if (num1 <= 0)
            {
                cout << "ERROR: Logarithm of non-positive numbers is not defined!\n";
                continue;
            }
            result = log10(num1);
            break;
        case 9:
            result = sin(num1 * M_PI / 180);                                                            // Convert degrees to radians
            break;
        case 10:
            result = cos(num1 * M_PI / 180);
            break;
        case 11:
            result = tan(num1 * M_PI / 180);
            break;
        default:
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        cout << "Result: " << result << endl;
    }

    return 0;
}
