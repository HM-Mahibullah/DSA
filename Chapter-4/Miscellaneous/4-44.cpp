/*
Page 112
Program 
4.14 Suppose A and B are n-element vector arrays in memory and X and Y are scalars. Write a program to find 
(a)  XA + YB and 
(b) A · B
Test the program using A = (16, −6, 7), B = (4, 2, −3), X = 2 and Y= −5.
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    const int n = 3; // Fixed size for this example
    int A[n] = {16, -6, 7}; // Given A vector
    int B[n] = {4, 2, -3};  // Given B vector
    int X = 2; // Given scalar X
    int Y = -5; // Given scalar Y

    // (a) Calculate XA + YB
    int result[n];
    for (int i = 0; i < n; i++) {
        result[i] = X * A[i] + Y * B[i];
    }

    cout << "Result of XA + YB:" << endl;
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // (b) Calculate A · B (dot product)
    int dot_product = 0;
    for (int i = 0; i < n; i++) {
        dot_product += A[i] * B[i];
    }

    cout << "Dot product of A and B: " << dot_product << endl;

    return 0;
}
/* Example Calculation:

Using the provided values:
•	A={16,−6,7}
•	B={4,2,−3}
•	X=2
•	Y=−5
Calculation of XA+YBXA + YBXA+YB:
•	First element: 2×16+(−5)×4=12
•	Second element: 2×(−6)+(−5)×2=−12−10=-22
•	Third element: 2×7+(−5)×(−3)=14+15=29
So, XA+YB={12,−22,29}.
Calculation of Dot Product A⋅BA \cdot BA⋅B:
•	16×4+(−6)×2+7×(−3)=64−12−21=31
The program will output:
Result of XA + YB:
12 -22 29 
Dot product of A and B: 31 */
