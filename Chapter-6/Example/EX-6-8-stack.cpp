/* https://www.youtube.com/watch?v=wySKkHmwwIo */
#include <iostream>
#include <stack>
using namespace std;

int factorialIterative(int N) {
    stack<int> s;
    int result = 1;

    // Push the initial value onto the stack
    s.push(N);

    // Process the stack until it's empty
    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (current > 0) {
            // Push the next value onto the stack
            s.push(current - 1);
            // Compute the factorial result iteratively
            result *= current;
        }
    }

    return result;
}

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;

    int result = factorialIterative(N);

    cout << "Factorial of " << N << " is " << result << endl;

    return 0;
}
