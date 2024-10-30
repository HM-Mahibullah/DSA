
// In insertion sort, each element is placed in its correct position relative to the sorted part of the array by shifting elements as needed.
#include <bits/stdc++.h>
using namespace std;

void Selection_sort(int a[], int size) {
    int index_min, temp;
    for (int i = 0; i < size - 1; i++) {
        index_min = i;
        // Find the minimum element in the unsorted portion
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[index_min]) { // For ascending order, use < instead of >
                index_min = j;
            }
        }
        // Swap only once, after the inner loop completes
        if (index_min != i) {
            temp = a[i];
            a[i] = a[index_min];
            a[index_min] = temp;
        }
    }
}

int main() {
    int a[] = {5, 2, 1, 0, 15};
    int size = sizeof(a) / sizeof(a[0]);
    Selection_sort(a, size);
    for (int elem : a) {
        cout << elem << " ";
    }
    cout << endl;
}


/*
Initial array: [5, 2, 1, 0, 15]
Sorting Process:
First Iteration (i = 0)
Find the minimum element from the unsorted portion (i = 0 to end):
index_min = 0 (starting with the first element, a[0] = 5).
j = 1: Compare a[1] = 2 with a[index_min] = 5. Update index_min = 1.
j = 2: Compare a[2] = 1 with a[index_min] = 2. Update index_min = 2.
j = 3: Compare a[3] = 0 with a[index_min] = 1. Update index_min = 3.
j = 4: Compare a[4] = 15 with a[index_min] = 0. No change.
Swap a[0] and a[3]:
After the swap, the array becomes [0, 2, 1, 5, 15].

Array after first pass: [0, 2, 1, 5, 15]
Second Iteration (i = 1)
Find the minimum element from the unsorted portion (i = 1 to end):
index_min = 1 (starting with a[1] = 2).
j = 2: Compare a[2] = 1 with a[index_min] = 2. Update index_min = 2.
j = 3: Compare a[3] = 5 with a[index_min] = 1. No change.
j = 4: Compare a[4] = 15 with a[index_min] = 1. No change.
Swap a[1] and a[2]:
After the swap, the array becomes [0, 1, 2, 5, 15].

Array after second pass: [0, 1, 2, 5, 15]
Third Iteration (i = 2)
Find the minimum element from the unsorted portion (i = 2 to end):
index_min = 2 (starting with a[2] = 2).
j = 3: Compare a[3] = 5 with a[index_min] = 2. No change.
j = 4: Compare a[4] = 15 with a[index_min] = 2. No change.
index_min remains 2, so no swap is needed.

Array after third pass: [0, 1, 2, 5, 15]
Fourth Iteration (i = 3)
Find the minimum element from the unsorted portion (i = 3 to end):
index_min = 3 (starting with a[3] = 5).
j = 4: Compare a[4] = 15 with a[index_min] = 5. No change.
index_min remains 3, so no swap is needed.

Array after fourth pass: [0, 1, 2, 5, 15]
Final Sorted Array
After all iterations, the array is sorted in ascending order:

Sorted Array: [0, 1, 2, 5, 15]
*/
