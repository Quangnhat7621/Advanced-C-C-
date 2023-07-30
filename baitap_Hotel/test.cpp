#include <iostream>

using namespace std;

int main() {
    uint8_t a = 5;
    int b;

    cout << "Enter b (0 to 255): ";
    cin >> b;
    b = (uint8_t)b;
    // Input validation
    if (b > 255) {
        cout << "Invalid input. b cannot be greater than 255." << endl;
        return 1; // Return an error code to indicate a problem.
    }

    cout << "Size of b: " << sizeof(b) << " bytes" << endl;
    // cout << "b: " << (uint8_t)b << endl; // Cast b to int to print its numeric value.

    if (b == a) {
        cout << "Equal";
    } else {
        cout << "Not equal";
    }

    return 0;
}
