#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high) {
    int pivot = a[high];//checkinhg its perfect position in the array
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <pivot)//if (a[j] <= pivot)
         {
            i++;// Postfix increment: x is assigned 0, then x becomes 1.
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
 
    return i + 1;

}

void quickSort(int a[], int low, int high) {
    if (low < high)// or  if (low <= high)
     {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
        
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
    int m = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, m - 1);//After the quickSort function completes execution, the original array a contains the sorted elements.
    //becausu we pass by referance.
    for (int i = 0; i < m; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

/* 
Example Walkthrough with the Array: 4, 2, 3, 9, 6, 10
Initial Array: 4, 2, 3, 9, 6, 10
Initial Array: [4, 2, 3, 9, 6, 10]
First Call: quickSort(a, 0, 5) (array: [4, 2, 3, 9, 6, 10], indices from 0 to 5)
Partition Call (partition(a, 0, 5)):
Pivot: 10 (the last element in the current sub-array).
i starts at -1.
j iterates from 0 to 4:
For j = 0, a[0] = 4 (less than 10). Increment i to 0. Swap a[0] with a[0] (no change).
For j = 1, a[1] = 2 (less than 10). Increment i to 1. Swap a[1] with a[1] (no change).
For j = 2, a[2] = 3 (less than 10). Increment i to 2. Swap a[2] with a[2] (no change).
For j = 3, a[3] = 9 (less than 10). Increment i to 3. Swap a[3] with a[3] (no change).
For j = 4, a[4] = 6 (less than 10). Increment i to 4. Swap a[4] with a[4] (no change).
Swap Pivot: Swap a[i + 1] with a[5] (pivot), which means swapping a[5] with itself (no change).
Partition Index: 5. The array remains: [4, 2, 3, 9, 6, 10].
Recursive Calls:
Left Sub-array: quickSort(a, 0, 4) (array: [4, 2, 3, 9, 6])
Right Sub-array: quickSort(a, 6, 5) (base case, doesn't proceed).
Second Call: quickSort(a, 0, 4) (array: [4, 2, 3, 9, 6], indices from 0 to 4)
Partition Call (partition(a, 0, 4)):
Pivot: 6 (last element of the current sub-array).
i starts at -1.
j iterates from 0 to 3:
For j = 0, a[0] = 4 (less than 6). Increment i to 0. Swap a[0] with a[0] (no change).
For j = 1, a[1] = 2 (less than 6). Increment i to 1. Swap a[1] with a[1] (no change).
For j = 2, a[2] = 3 (less than 6). Increment i to 2. Swap a[2] with a[2] (no change).
For j = 3, a[3] = 9 (greater than 6, so no swap).
Swap Pivot: Swap a[i + 1] with a[4], which means swapping a[3] with a[4]. The array becomes: [4, 2, 3, 6, 9, 10].
Partition Index: 3.
Recursive Calls:
Left Sub-array: quickSort(a, 0, 2) (array: [4, 2, 3])
Right Sub-array: quickSort(a, 4, 4) (base case, doesn't proceed).
Third Call: quickSort(a, 0, 2) (array: [4, 2, 3], indices from 0 to 2)
Partition Call (partition(a, 0, 2)):

Pivot: 3 (last element of the current sub-array).
i starts at -1.
j iterates from 0 to 1:
For j = 0, a[0] = 4 (greater than 3, so no swap).
For j = 1, a[1] = 2 (less than 3). Increment i to 0. Swap a[0] with a[1]. The array becomes: [2, 4, 3, 6, 9, 10].
Swap Pivot: Swap a[i + 1] with a[2], which means swapping a[1] with a[2]. The array becomes: [2, 3, 4, 6, 9, 10].
Partition Index: 1.
Recursive Calls:

Left Sub-array: quickSort(a, 0, 0) (base case, doesn't proceed).
Right Sub-array: quickSort(a, 2, 2) (base case, doesn't proceed).
At this point, the left sub-array is fully sorted.

Fourth Call: quickSort(a, 4, 4) (base case, doesn't proceed).
Fifth Call: quickSort(a, 6, 5) (base case, doesn't proceed).
Final Sorted Array:
After completing all the recursive calls, the array is now sorted: [2, 3, 4, 6, 9, 10].

Summary of Key Points:
Partitioning:
The pivot is chosen as the last element of the sub-array in each call.
The elements smaller than the pivot are moved to the left, and larger ones remain on the right.
Recursion:
The array is recursively partitioned into smaller sub-arrays until base cases (sub-arrays of size 1) are reached.
In-place Sorting:
The array is modified in-place, meaning the original array is sorted without using additional storage.

 */
