//[Merge Sort visualization](https://visualgo.net/en/sorting)
//[Youtube link](https://www.youtube.com/watch?v=CM4uV1vLWow)

#include <iostream>
using namespace std;

// Function to merge two subarrays
void mergeSort(int arr[], int low, int mid, int high)
{
    int i = low;       // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = low;       // Starting index to be merged into temp
    int temp[100];   // Temporary array to store sorted elements

    // Merging the two subarrays into temp
    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])//   or   if (arr[i] >= arr[j])
        {
            temp[k++] = arr[j++];
            /*
                  or you can write
            temp[k]=arr[j];
            k++;
            j++;

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
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    // Copy the sorted elements back to the original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

// Recursive function to implement merge sort
void merge(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        // Recursively sort the left and right halves
        merge(arr, low, mid);
        merge(arr, mid + 1, high);

        // Merge the sorted halves
        mergeSort(arr, low, mid, high);
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
    /*
      for (int i : array)
    {
        cout << i << ' ';
    }
    */

    merge(arr, 0, n - 1);

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
First call: merge(arr, 0, mid) where mid = (0 + 6) / 2 = 3 (sorting left half {38, 27, 43, 3})

Inside this call:
First sub-call: merge(arr, 0, 1) where mid = 0 (sorting the left half {38, 27})

First sub-sub-call: merge(arr, 0, 0) (base case, no further recursion)
Second sub-sub-call: merge(arr, 1, 1) (base case, no further recursion)
Third sub-sub-call: merge(arr, 0, 0, 1) merges {38} and {27} into {27, 38}

প্রথম Function এর কাজ শেষ তাই Second function  কল করা হয়েছে.

Second sub-call: merge(arr, 2, 3) where mid = 2 (sorting the right half {43, 3})

First sub-sub-call: merge(arr, 2, 2) (base case, no further recursion)
Second sub-sub-call: merge(arr, 3, 3) (base case, no further recursion)
Third sub-sub-call: merge(arr, 2, 2, 3) merges {43} and {3} into {3, 43}
Final sub-call: merge(arr, 0, 1, 3) merges {27, 38} and {3, 43} into {3, 27, 38, 43}

Second call: merge(arr, mid + 1, high) where mid = 3 (sorting right half {9, 82, 10})

First sub-call: merge(arr, 4, 5) where mid = 4 (sorting the left half {9, 82})

First sub-sub-call: merge(arr, 4, 4) (base case, no further recursion)
Second sub-sub-call: merge(arr, 5, 5) (base case, no further recursion)
Third sub-sub-call: merge(arr, 4, 4, 5) merges {9} and {82} into {9, 82}
Second sub-call: merge(arr, 6, 6) (base case, no further recursion)

Final sub-call: merge(arr, 4, 5, 6) merges {9, 82} and {10} into {9, 10, 82}

Final call: merge(arr, 0, 3, 6) merges {3, 27, 38, 43} and {9, 10, 82} into {3, 9, 10, 27, 38, 43, 82}
Final Result:
{3, 9, 10, 27, 38, 43, 82}

*/
