#include <iostream>
using namespace std;

int fibonacciRecursive(int N)
{
    // Base case: If N is 0 or 1, return N directly
    if (N == 0 || N == 1)
    {
        return N;
    }

    // Recursive case: Calculate Fibonacci(N-2) and Fibonacci(N-1)
    int fibA = fibonacciRecursive(N - 2);
    int fibB = fibonacciRecursive(N - 1);

    // Return the sum of the two previous Fibonacci numbers
    return fibA + fibB;
}

int main()
{
    int N;

    // Prompt the user for input
    cout << "Enter a number: ";
    cin >> N;

    // Calculate the Fibonacci number for the given N
    int result = fibonacciRecursive(N);

    // Display the result
    cout << "Fibonacci of " << N << " is " << result << endl;

    return 0;
}

/* Example: Calculate Fibonacci(5)
Let's walk through the example where N = 5.
1.	Initial Call:
o	fibonacciRecursive(5) is called.
2.	Recursive Breakdown:
o	fibonacciRecursive(5) calls fibonacciRecursive(3) and fibonacciRecursive(4).
3.	Further Breakdown:
o	fibonacciRecursive(3) calls fibonacciRecursive(1) and fibonacciRecursive(2).
	fibonacciRecursive(1) returns 1 (base case).
	fibonacciRecursive(2) calls fibonacciRecursive(0) and fibonacciRecursive(1).
	fibonacciRecursive(0) returns 0 (base case).
	fibonacciRecursive(1) returns 1 (base case).
	fibonacciRecursive(2) returns 0 + 1 = 1.
o	fibonacciRecursive(3) returns 1 + 1 = 2.
4.	Similarly:
o	fibonacciRecursive(4) calls fibonacciRecursive(2) and fibonacciRecursive(3):
	fibonacciRecursive(2) returns 1 (as calculated earlier).
	fibonacciRecursive(3) returns 2 (as calculated earlier).
o	fibonacciRecursive(4) returns 1 + 2 = 3.
5.	Final Calculation:
o	fibonacciRecursive(5) returns 2 + 3 = 5.

 */