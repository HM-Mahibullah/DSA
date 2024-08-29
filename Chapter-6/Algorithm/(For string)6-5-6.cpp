#include <bits/stdc++.h>
using namespace std;

int partition(vector<char>& a, int low, int high) {
    char pivot = a[high];  // Using the last element as pivot
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot)  // Compare characters lexicographically
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<char>& a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.length();

    // Convert string to vector of characters
    vector<char> a(s.begin(), s.end());

    quickSort(a, 0, n - 1);  // Sort the vector

    cout << "Sorted string: ";
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << endl;

    return 0;
}
/* Step-by-Step Execution of QuickSort
1.	First Call to quickSort(a, 0, 13)
o	Subarray: ['D', 'A', 'T', 'A', 'S', 'T', 'R', 'U', 'C', 'T', 'U', 'R', 'E', 'S']
o	Pivot: 'S' (last element)
o	Initial index i = -1
o	Partitioning Process:
	'D' < 'S' → Swap 'D' with itself, increment i to 0
	'A' < 'S' → Swap 'A' with itself, increment i to 1
	'T' > 'S' → No swap
	'A' < 'S' → Swap 'A' with 'T', increment i to 2
	'S' = 'S' → No swap
	'T' > 'S' → No swap
	'R' < 'S' → Swap 'R' with 'T', increment i to 3
	'U' > 'S' → No swap
	'C' < 'S' → Swap 'C' with 'T', increment i to 4
	'T' > 'S' → No swap
	'U' > 'S' → No swap
	'R' < 'S' → Swap 'R' with 'T', increment i to 5
	'E' < 'S' → Swap 'E' with 'T', increment i to 6
o	After partitioning, swap the pivot 'S' with 'T' at i+1 = 7.
o	Array after partitioning: ['D', 'A', 'A', 'R', 'C', 'R', 'E', 'S', 'S', 'T', 'U', 'U', 'T', 'T']
o	Pivot index: 7
o	Now recursively sort the left subarray (0-6) and right subarray (8-13).
2.	Sorting the Left Subarray (quickSort(a, 0, 6)):
o	Subarray: ['D', 'A', 'A', 'R', 'C', 'R', 'E']
o	Pivot: 'E'
o	Partitioning Process:
	'D' < 'E' → Swap 'D' with itself, increment i to 0
	'A' < 'E' → Swap 'A' with itself, increment i to 1
	'A' < 'E' → Swap 'A' with itself, increment i to 2
	'R' > 'E' → No swap
	'C' < 'E' → Swap 'C' with 'R', increment i to 3
	'R' > 'E' → No swap
o	After partitioning, swap the pivot 'E' with 'R' at i+1 = 4.
o	Array after partitioning: ['D', 'A', 'A', 'C', 'E', 'R', 'R', 'S', 'S', 'T', 'U', 'U', 'T', 'T']
o	Pivot index: 4
o	Recursively sort the left subarray (0-3) and right subarray (5-6).
3.	Sorting the Right Subarray (quickSort(a, 8, 13)):
o	Subarray: ['S', 'T', 'U', 'U', 'T', 'T']
o	Pivot: 'T'
o	Partitioning Process:
	'S' < 'T' → Swap 'S' with itself, increment i to 7
	'T' = 'T' → No swap
	'U' > 'T' → No swap
	'U' > 'T' → No swap
	'T' = 'T' → No swap
o	After partitioning, swap the pivot 'T' with 'U' at i+1 = 9.
o	Array after partitioning: ['D', 'A', 'A', 'C', 'E', 'R', 'R', 'S', 'S', 'T', 'T', 'U', 'U', 'T']
o	Pivot index: 10
o	Recursively sort the left subarray (8-9) and right subarray (11-13).
Final Sorted Array
After all recursive calls complete, the fully sorted array is:
['A', 'A', 'C', 'D', 'E', 'R', 'R', 'S', 'S', 'T', 'T', 'T', 'U', 'U']

 */