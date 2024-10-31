#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    // Pushing 5 elements
    for (int i = 1; i <= 5; ++i) {
        st.push(i);
        cout << "Pushed: " << i << endl;
    }

    // Printing stack contents
    cout << "Stack contents (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
