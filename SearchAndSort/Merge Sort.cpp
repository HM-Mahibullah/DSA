[Merge Sort visualization](https://visualgo.net/en/sorting)
[Youtube link](https://www.youtube.com/watch?v=CM4uV1vLWow)

#include <iostream>
using namespace std;

// Function to merge two subarrays
void merge(int arr[], int l, int mid, int h)
{
    int i = l;       // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = l;       // Starting index to be merged into temp
    int temp[100];   // Temporary array to store sorted elements

    // Merging the two subarrays into temp
    while (i <= mid && j <= h)
    {
        if (arr[i] > arr[j])//   or   if (arr[i] >= arr[j])
        {
            temp[k++] = arr[j++];
            /*
                  or you can write
            temp[k]=arr[i];
            k++;
            i++;

            */
        }
        else
        {
            temp[k++] = arr[i++];

            /*
                 or you can write
           temp[k]=arr[j];
           k++;
           j++;

           */
        }
    }

    // Copy remaining elements from the left subarray, if any
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from the right subarray, if any
    while (j <= h)
    {
        temp[k++] = arr[j++];
    }

    // Copy the sorted elements back to the original array
    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[i];
    }
}

// Recursive function to implement merge sort
void mergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;

        // Recursively sort the left and right halves
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);

        // Merge the sorted halves
        merge(arr, l, mid, h);
    }
}

// Helper function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
   int arr[] = {4,1,20,12,11,9,5}; //int arr[] = {38, 38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
/*

Initial Array:
{38, 27, 43, 3, 9, 82, 10}
Here's how this process unfolds:
Let's break this down using an example where the array is {38, 27, 43, 3, 9, 82, 10}.

Step-by-Step Execution:
First call: mergeSort(arr, 0, mid) where mid = (0 + 6) / 2 = 3 (sorting left half {38, 27, 43, 3})

Inside this call:
First sub-call: mergeSort(arr, 0, 1) where mid = 0 (sorting the left half {38, 27})

First sub-sub-call: mergeSort(arr, 0, 0) (base case, no further recursion)
Second sub-sub-call: mergeSort(arr, 1, 1) (base case, no further recursion)
Third sub-sub-call: merge(arr, 0, 0, 1) merges {38} and {27} into {27, 38}

প্রথম Function এর কাজ শেষ তাই Second function  কল করা হয়েছে.

Second sub-call: mergeSort(arr, 2, 3) where mid = 2 (sorting the right half {43, 3})

First sub-sub-call: mergeSort(arr, 2, 2) (base case, no further recursion)
Second sub-sub-call: mergeSort(arr, 3, 3) (base case, no further recursion)
Third sub-sub-call: merge(arr, 2, 2, 3) merges {43} and {3} into {3, 43}
Final sub-call: merge(arr, 0, 1, 3) merges {27, 38} and {3, 43} into {3, 27, 38, 43}

Second call: mergeSort(arr, mid + 1, h) where mid = 3 (sorting right half {9, 82, 10})

First sub-call: mergeSort(arr, 4, 5) where mid = 4 (sorting the left half {9, 82})

First sub-sub-call: mergeSort(arr, 4, 4) (base case, no further recursion)
Second sub-sub-call: mergeSort(arr, 5, 5) (base case, no further recursion)
Third sub-sub-call: merge(arr, 4, 4, 5) merges {9} and {82} into {9, 82}
Second sub-call: mergeSort(arr, 6, 6) (base case, no further recursion)

Final sub-call: merge(arr, 4, 5, 6) merges {9, 82} and {10} into {9, 10, 82}

Final call: merge(arr, 0, 3, 6) merges {3, 27, 38, 43} and {9, 10, 82} into {3, 9, 10, 27, 38, 43, 82}
Final Result:
{3, 9, 10, 27, 38, 43, 82}

*/
