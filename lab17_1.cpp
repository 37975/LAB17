#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int nA, nB;
    int *A, *B, **C;

    // Input Array A
    cout << "Length of A: ";
    cin >> nA;
    A = new int[nA]; // Correct allocation
    cout << "Input Array A: ";
    for (int i = 0; i < nA; i++) cin >> A[i];

    // Input Array B
    cout << "Length of B: ";
    cin >> nB;
    B = new int[nB]; // Correct allocation
    cout << "Input Array B: ";
    for (int i = 0; i < nB; i++) cin >> B[i];

    // Allocate memory for 2D array C
    C = new int*[nA]; 
    for (int i = 0; i < nA; i++) {
        C[i] = new int[nB]; // Allocate each row
    }

    // Compute C[i][j] = A[i] * B[j]
    for (int i = 0; i < nA; i++) {
        for (int j = 0; j < nB; j++) {
            C[i][j] = A[i] * B[j];
        }
    }

    // Output Multiplication Table
    cout << "\n" << setw(6) << " ";
    for (int i = 0; i < nB; i++) {
        cout << setw(5) << B[i] << " ";
    }
    cout << "\n-----------------------------\n";

    for (int i = 0; i < nA; i++) {
        cout << setw(5) << A[i] << " ";
        for (int j = 0; j < nB; j++) {
            cout << setw(5) << C[i][j] << " ";
        }
        cout << "\n";
    }

    // Deallocate memory
    delete[] A;
    delete[] B;
    for (int i = 0; i < nA; i++) {
        delete[] C[i];
    }
    delete[] C;

    return 0;
}
