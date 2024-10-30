/*
Page 75
Algorithm 4.4: (Bubble Sort) BUBBLE(DATA, N)
Here DATA is an array with N elements. This algorithm sorts the elements in DATA.
1. Repeat Steps 2 and 3 for K = 1 to N – 1.
2.        Set PTR := 1. [Initializes pass pointer PTR.]
3.        Repeat while PTR ≤ N – K: [Executes pass.]
(a) If DATA[PTR] < DATA[PTR + 1], then:
Interchange DATA[PTR] and DATA[PTR + 1].
[End of If structure.]
(b) Set PTR := PTR + 1.
[End of inner loop.]
[End of Step 1 outer loop.]
4. Exit
*/

//Ascending
#include <bits/stdc++.h>
using namespace std;
void Bubble_sort(int a[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j +1] = temp;
            }
        }
    }
}
int main()

{
    int a[] = {
        1,
        2,
        3,
        4,
        5,
        8,
        11,
        55};
    int size = sizeof(a) / sizeof(a[0]);
    Bubble_sort(a, size);
    cout << "Output=";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}
//Descending order
/*
#include <bits/stdc++.h>
using namespace std;
void Bubble_sort(int a[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i-1; j++)
        {
            if (a[j] < a[j+1])   /এখানে > চিহ্ন পরিবর্তন করলেই Descending order হবে.            {
                temp = a[j];
                a[j] = a[j+1];
                a[j +1] = temp;
            }
        }
    }
}
int main()

{
    int a[] = {
        1,
        2,
        3,
        4,
        5,
        8,
        11,
        55};
    int size = sizeof(a) / sizeof(a[0]);
    Bubble_sort(a, size);
    cout << "Output=";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}
*/


