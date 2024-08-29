#include <iostream>
using namespace std;

int fibonacciRecursive(int N)
{
    // Base case: If N is 0 or 1, return N directly
    if (N == 0 || N == 1)
    {
        return N;
    }
    return fibonacciRecursive(N - 1) + fibonacciRecursive(N - 2);
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
