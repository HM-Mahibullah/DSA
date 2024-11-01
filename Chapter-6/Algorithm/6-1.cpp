#include <bits/stdc++.h>
using namespace std;

const int Max_stack = 5; // Maximum number of stacks

// Function to push an element onto the stack array
void STACK(stack<int> sk[], int &top, int element) {
    // Check for overflow condition
    if (Max_stack - 1 == top) {
        cout << "Overflow" << endl;
        return;
    } else {
        top++;
        sk[top].push(element); // Push the element onto the stack
    }
}

int main() {
    int n, element;
    stack<int> sk[Max_stack]; // Array of stacks
    int top = -1; // Initialize top to -1

    cout << "Enter the number of elements: ";
    cin >> n; // Input number of elements

    // Loop to input elements and push onto stacks
    for (int i = 0; i < n; i++) {
        cout << "Enter element: ";
        cin >> element;
        STACK(sk, top, element); // Push element onto the stack
    }

    // Loop to pop and display elements from the stacks
    for (int i = 0; i <= top; i++) {
        cout << sk[i].top() << " "; // Display the top element
        sk[i].pop(); // Remove the top element
    }
    cout << endl; // New line after displaying elements

    return 0; // Indicate successful completion
}

/*
Enter the number of items to push: 6
Enter item 1: 5
Enter item 2: 8
Enter item 3: 6
Enter item 4: 5
Enter item 5: 5
Enter item 6: 4
OVERFLOW
Stack contents (top to bottom): 5 5 6 8 5
*/
