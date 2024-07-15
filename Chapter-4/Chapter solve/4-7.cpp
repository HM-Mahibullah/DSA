#include <bits/stdc++.h>
using namespace std;

int index = -1;

int BinarySearch(string s[], string search, int size) {
    int beggin = 0, end = size - 1, mid;
    while (beggin <= end) {
        mid = (beggin + end) / 2;
        if (s[mid] == search) {
            return index = mid;
        } else {
            if (s[mid] < search) {
                beggin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return index = beggin; // Return the position where the element should be inserted
}

void EnterElementsFunction(string s[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> s[i];
    }
}

void INSERT(string s[], int &size, int K, string ITEM) {
    for (int i = size; i > K; i--) 
    {
        s[i] = s[i - 1];//Transfer element  such as index[5] to index[4].
    }
    s[K] = ITEM;
    size++;
}

int main()
{
    int size = 5;
    string s[100], search;

    cout << "Enter " << size << " sorted elements:\n";
    EnterElementsFunction(s, size);
    sort(s,s+size);

    cout << "Enter your Keyword\n";
    cin >> search;
    
    BinarySearch(s, search, size);

    if (index != -1 && s[index] == search)
    {
        cout << "Index of element (with zero base index) = " << index << endl;
    }
    else 
    {
        cout << "Element not found in array. Inserting at correct position.\n";
        INSERT(s, size, index, search);//Index value is =0 because of (index =beggin).
        
    cout << "Updated array:\n";
    for (int i = 0; i < size; i++) 
    {
        cout << s[i] << " ";
    }
    cout << endl;
    }


    return 0;
}
/*
   First run
Enter 5 sorted elements:
a
b
c
d
e
Enter your Keyword
e
Index of element (with zero base index) = 4


    Second run

Enter 5 sorted elements:
a
b
c
e
f
Enter your Keyword
d
Element not found in array. Inserting at correct position.
Updated array:
a b c d e f
*/
