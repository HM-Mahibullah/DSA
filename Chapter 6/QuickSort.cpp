#include <iostream>
using namespace std;

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
        
    }
    
}

int main() {
   int m;
    cout << "Enter the number of elements: ";
    cin >> m;

    int a[m];
    cout << "Enter the elements:\n";
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, n - 1);//After the quickSort function completes execution, the original array a contains the sorted elements.
    //becausu we pass by referance.
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
