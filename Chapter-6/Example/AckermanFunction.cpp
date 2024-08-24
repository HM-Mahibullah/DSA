/* https://www.youtube.com/watch?v=OoT20q6yvGY

                 //Ackerman function(recursion function)//
A(m, n) = n + 1 if m = 0;

A(m - 1, 1)  if m > 0 and n = 0;

A(m - 1, A(m, n - 1)) if m > 0 and  n > 0; */

#include <iostream>
using namespace std;

int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main() {
    int m, n;
    cout << "Enter values for m and n: ";
    cin >> m >> n;

    cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n) << endl;

    return 0;
}

/* Summary of Recursive Steps for ackermann(1, 2)
1.	ackermann(1, 2) calls ackermann(0, ackermann(1, 1))
2.	ackermann(1, 1) calls ackermann(0, ackermann(1, 0))
3.	ackermann(1, 0) calls ackermann(0, 1) which returns 2
4.	ackermann(1, 0) returns 2, so ackermann(1, 1) calls ackermann(0, 2) which returns 3 
5.	ackermann(1, 2) returns 3, so ackermann(1, 2) calls ackermann(0, 3) which returns 4

 */
