#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high) {
    int pivot = a[high];//checkinhg its perfect position in the array
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <pivot)//if (a[j] <= pivot)
         {
            i++;
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
•	Call quickSort(a, 0, 5)
o	The array is from index 0 to 5.
•	First Partition Call (partition(a, 0, 5)):
o	Pivot: 10 (last element of the current sub-array).
o	Initial i: -1 (low - 1).
o	Loop: We iterate from j = 0 to j = 4:
	For j = 0: a[0] = 4 (less than pivot), so i = 0 and swap a[0] with a[0] (no change).
	For j = 1: a[1] = 2 (less than pivot), so i = 1 and swap a[1] with a[1] (no change).
	For j = 2: a[2] = 3 (less than pivot), so i = 2 and swap a[2] with a[2] (no change).
	For j = 3: a[3] = 9 (less than pivot), so i = 3 and swap a[3] with a[3] (no change).
	For j = 4: a[4] = 6 (less than pivot), so i = 4 and swap a[4] with a[4] (no change).
o	Swap Pivot: After the loop, swap a[i + 1] with a[high], which means swapping a[5] with a[5]. The array remains unchanged.
o	Partition Index: The partition index is 5.
o	Array after Partitioning: 4, 2, 3, 9, 6, 10
•	Recursive Calls:
o	First Recursive Call: quickSort(a, 0, 4) (left sub-array before the pivot).
	The pivot is 6. After partitioning, the array becomes: 4, 2, 3, 6, 9, 10. Partition index is 3.
	Recursive calls continue on sub-arrays: quickSort(a, 0, 2) and quickSort(a, 4, 4).
o	Second Recursive Call: quickSort(a, 0, 2) (left sub-array before 6(so this function is not call)):
	The pivot is 3. After partitioning, the array becomes: 2, 3, 4, 6, 9, 10. Partition index is 1.
	Recursive calls continue on sub-arrays: quickSort(a, 0, 0) and quickSort(a, 2, 2).
o	Remaining Recursive Calls:
	The smaller sub-arrays are already sorted, so the recursion ends.
•	Final Sorted Array: 2, 3, 4, 6, 9, 10
Key Points:
•	Pivot Selection: The last element of the current sub-array is chosen as the pivot.
•	Partitioning: Elements smaller than the pivot are moved to the left, and larger ones to the right.
•	Recursion: The array is recursively partitioned and sorted.



 */