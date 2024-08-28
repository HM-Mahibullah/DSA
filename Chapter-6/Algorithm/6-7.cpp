/* https://www.youtube.com/watch?v=wySKkHmwwIo */

#include <iostream>
using namespace std;

int factorialRecursive( int N)
{
    if (N == 0)
    {
        return 1;
    }

    int smallAns = factorialRecursive( N - 1); // Call FACTORIAL for N-1
    return N * smallAns;                            // Multiply FACT by N
}

int main()
{
    int N;
    cout << "Enter a number: ";
    cin >> N;

    
    int result=factorialRecursive(N);

    cout << "Factorial of " << N << " is " << result << endl;

    return 0;
}
