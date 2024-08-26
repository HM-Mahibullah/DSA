#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high) {
    int pivot = a[high];  // Choosing the pivot element
    int i = low - 1;      // Index of the smaller element
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);  // Swap elements smaller than pivot
        }
    }
    swap(a[i + 1], a[high]);   // Swap the pivot to its correct position
    return i + 1;              // Return the pivot index
}

void quickSort(int a[], int low, int high) {
    // Stack to store pairs of (low, high) indices
    stack<pair<int, int>> s;

    // Push the initial indices of the array onto the stack
    s.push({low, high});

    // Process the stack until it's empty
    while (!s.empty()) {
        // Pop the top (low, high) pair from the stack
        pair<int, int> current = s.top();
        s.pop();

        int low = current.first;
        int high = current.second;

        // Partition the subarray and get the pivot index
        int p = partition(a, low, high);

        // If there are elements on the left side of the pivot, push left subarray to the stack
        if (p - 1 > low) {
            s.push({low, p - 1});
        }

        // If there are elements on the right side of the pivot, push right subarray to the stack
        if (p + 1 < high) {
            s.push({p + 1, high});
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Perform QuickSort using the stack-based implementation
    quickSort(a, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}



/* 
Example Walkthrough
Let's walk through the code with the example array: [4, 2, 3, 9, 6, 10].
1.	Initial Call to QuickSort:
o	The stack starts with the entire array: s = [(0, 5)].
2.	First Iteration:
o	The top subarray (0, 5) is popped from the stack.
o	The partition function is called with this subarray, with the pivot as 10.
o	The partition process places all elements smaller than 10 to the left and all greater elements to the right, resulting in the array [4, 2, 3, 9, 6, 10] with the pivot index p = 5.
o	The stack is updated with the left subarray (0, 4): s = [(0, 4)].
3.	Second Iteration:
o	The top subarray (0, 4) is popped from the stack.
o	The partition function is called with this subarray, with the pivot as 6.
o	The partition process results in the array [4, 2, 3, 6, 9, 10] with the pivot index p = 3.
o	The stack is updated with the left subarray (0, 2) and the right subarray (4, 4): s = [(0, 2), (4, 4)].
4.	Third Iteration:
o	The top subarray (4, 4) is popped from the stack, but since it has only one element, no further partitioning is needed.
o	Next, the subarray (0, 2) is popped from the stack.
o	The partition function is called with this subarray, with the pivot as 3.
o	The partition process results in the array [2, 3, 4, 6, 9, 10] with the pivot index p = 1.
o	The stack is updated with the left subarray (0, 0) and the right subarray (2, 2): s = [(0, 0), (2, 2)].
5.	Final Iterations:
o	The subarrays (2, 2) and (0, 0) are popped from the stack, but since both contain only one element, no further partitioning is needed.
o	The stack is now empty, so the sorting is complete.
Final Output
After sorting, the array is [2, 3, 4, 6, 9, 10], and the code prints the sorted array.


 */