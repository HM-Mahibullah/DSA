/*void POP(int STACK[], int &TOP, int &ITEM) {
    if (TOP == 0) {
        cout << "UNDERFLOW" << endl;
        return;
    }
    ITEM = STACK[TOP];
    TOP = TOP - 1;
}
*/
#include <bits/stdc++.h>
using namespace std;

// Function to pop an element from a specific stack
void POP(stack<int> sk[], int &top) {
    if (top == -1) { // Check for underflow condition
        cout << "UNDERFLOW" << endl;
        return;
    }

    int item; // Variable to hold the popped item

    // Attempt to pop from the current top stack
    if (!sk[top].empty()) {
        item = sk[top].top(); // Get the top element
        sk[top].pop(); // Remove the top element
        cout << "Popped from stack " << top << ": " << item << endl; // Display the popped item
    } else {
        cout << "Current stack " << top << " is empty. Moving to the next stack." << endl;
        top--; // Move to the next stack
        POP(sk, top); // Try popping from the next stack
    }
}

int main() {
    const int Max_stack = 5; // Maximum number of stacks
    stack<int> sk[Max_stack]; // Array of stacks
    int top = -1; // Initialize top to -1
    int n, element;

    cout << "Enter the number of elements to push: ";
    cin >> n; // Input number of elements

    // Loop to input elements and push onto stacks
    for (int i = 0; i < n; i++) {
        cout << "Enter element: ";
        cin >> element;
        if (top < Max_stack - 1) { // Check for overflow
            top++; // Increment top index
            sk[top].push(element); // Push the element onto the stack
        } else {
            cout << "Overflow: Cannot push more elements." << endl;
        }
    }

    // Pop elements from the stacks
    for (int i = 0; i < n; i++) {
        POP(sk, top); // Pop from the stack
    }

    return 0; // Indicate successful completion
}
