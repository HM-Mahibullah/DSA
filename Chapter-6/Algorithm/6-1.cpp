#include <iostream>
using namespace std;

// PUSH function
void PUSH(int STACK[], int &TOP, int MAXSTK, int ITEM) {
    if (TOP == MAXSTK - 1) { // Check if stack is full
        cout << "OVERFLOW" << endl;
        return;
    }
    TOP = TOP + 1;
    STACK[TOP] = ITEM;
}

int main() {
    int MAXSTK = 5; // Maximum stack size
    int STACK[MAXSTK]; // Stack array
    int TOP = -1; // Initialize TOP to -1 (empty stack)

    int n, ITEM;
    cout << "Enter the number of items to push: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter item " << i + 1 << ": ";
        cin >> ITEM;
        PUSH(STACK, TOP, MAXSTK, ITEM); // Call PUSH to add item to stack
    }

    // Displaying the contents of the stack
    cout << "Stack contents (top to bottom): ";
    for (int i = TOP; i >= 0; i--) {
        cout << STACK[i] << " ";
    }
    cout << endl;

    return 0;
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
