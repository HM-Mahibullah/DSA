
// In insertion sort, each element is placed in its correct position relative to the sorted part of the array by shifting elements as needed.
#include <bits/stdc++.h>
using namespace std;

void Selection_sort(int a[], int size) {
    int min, temp;
    for (int i = 0; i < size - 1; i++) {
        min = i;
        // Find the minimum element in the unsorted portion
        for (int j = i + 1; j < size;j++) {
            if (a[j] < a[min]) { // For ascending order
            min = j;
            }
        }
        // Swap only once, after the inner loop completes
        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

int main() {
    int a[] = {4, 5, 2, 1, 3, 15};
    int size = sizeof(a) / sizeof(a[0]);
    Selection_sort(a, size);
    for (int elem : a) {
        cout << elem << " ";
    }
    cout << endl;
}

/*
Initial array: [4, 5, 2, 1, 3, 15]
Sorting Process:
First Iteration (i = 0):
- Start with min = 0 (a[0] = 4).
- j = 1: Compare a[1] = 5 with a[min] = 4. No change.
- j = 2: Compare a[2] = 2 with a[min] = 4. Update min = 2.
- j = 3: Compare a[3] = 1 with a[min] = 2. Update min = 3.
- j = 4: Compare a[4] = 3 with a[min] = 1. No change.
- Swap a[0] and a[3]: [1, 5, 2, 4, 3, 15]
Array after first pass: [1, 5, 2, 4, 3, 15]

Second Iteration (i = 1):
- Start with min = 1 (a[1] = 5).
- j = 2: Compare a[2] = 2 with a[min] = 5. Update min = 2.
- j = 3: Compare a[3] = 4 with a[min] = 2. No change.
- j = 4: Compare a[4] = 3 with a[min] = 2. No change.
- Swap a[1] and a[2]: [1, 2, 5, 4, 3, 15]
Array after second pass: [1, 2, 5, 4, 3, 15]

Third Iteration (i = 2):
- Start with min = 2 (a[2] = 5).
- j = 3: Compare a[3] = 4 with a[min] = 5. Update min = 3.
- j = 4: Compare a[4] = 3 with a[min] = 4. Update min = 4.
- Swap a[2] and a[4]: [1, 2, 3, 4, 5, 15]
Array after third pass: [1, 2, 3, 4, 5, 15]

Fourth Iteration (i = 3):
- Start with min = 3 (a[3] = 4).
- j = 4: Compare a[4] = 5 with a[min] = 4. No change.
- No swap is needed since min remains 3.
Array after fourth pass: [1, 2, 3, 4, 5, 15]

Final Sorted Array:
After all iterations, the array is sorted in ascending order:
Sorted Array: [1, 2, 3, 4, 5, 15]
*/
