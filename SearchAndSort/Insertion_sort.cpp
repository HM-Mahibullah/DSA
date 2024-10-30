/*
[insertion sort visualization](https://visualgo.net/en/sorting)
[YouTube link](https://www.youtube.com/watch?v=iQNZAOw67zM&t=690s)
*/
#include <bits/stdc++.h>
using namespace std;
int Insertion_sort(int a[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int item= a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > item)
		{
			a[j + 1] = a[j];
			j = j - 1; // or j--;
		}
		a[j + 1] = item;
	}
}
int main()
{
	int a[5]; // Array is fixed length data types
	int size = sizeof(a) / sizeof(a[0]);
	cout << "Enter Five Elements";
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	int index = Insertion_sort(a, size);
	cout << "After sorting array=";
	for (int b : a)
	{
		cout << b << " ";
	}
}

/*
Initial array: [4, 2, 5, 3, 1]
Sorting Process:
First iteration (i = 1):

item = 2
Compare with a[0] = 4: Since 4 > 2, shift 4 to the right.
Insert 2 into position a[0].
Array after first pass: [2, 4, 5, 3, 1]
Second iteration (i = 2):

item = 5
Compare with a[1] = 4: Since 4 > 5, no shifts are needed.
Array after second pass: [2, 4, 5, 3, 1]
Third iteration (i = 3):

item = 3
Compare with a[2] = 5: Since 5 > 3, shift 5 to the right.
Compare with a[1] = 4: Since 4 > 3, shift 4 to the right.
Insert 3 into position a[1].
Array after third pass: [2, 3, 4, 5, 1]
Fourth iteration (i = 4):

item = 1
Compare with a[3] = 5: Since 5 > 1, shift 5 to the right.
Compare with a[2] = 4: Since 4 > 1, shift 4 to the right.
Compare with a[1] = 3: Since 3 > 1, shift 3 to the right.
Compare with a[0] = 2: Since 2 > 1, shift 2 to the right.
Insert 1 into position a[0].
Array after fourth pass: [1, 2, 3, 4, 5]
*/
