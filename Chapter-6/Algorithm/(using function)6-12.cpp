#include <iostream>
using namespace std;

void QINSERT(int QUEUE[], int N, int &FRONT, int &REAR, int ITEM)
{
    // Check if the queue is full
    if ((FRONT == 1 && REAR == N) || (FRONT == REAR + 1))
    {
        cout << "OVERFLOW" << endl;
        return;
    }

    // Find the new value of REAR
    if (FRONT == -1)
    { // Queue is initially empty
        FRONT = 0;
        REAR = 0;
    }
    else if (REAR == N - 1)
    {
        REAR = 0;
        /* The condition REAR == N - 1 checks whether REAR is currently at the last position of the array (N-1).
                 Here, N is the maximum size of the queue. */
    }
    else
    {
        REAR = REAR + 1;
    }

    // Insert the new element
    QUEUE[REAR] = ITEM;
}

void QDELETE(int QUEUE[], int N, int &FRONT, int &REAR, int &ITEM)
{
    // Check if the queue is empty
    if (FRONT == -1)
    {
        cout << "UNDERFLOW" << endl;
        return;
    }

    // Assign the front element to ITEM
    ITEM = QUEUE[FRONT];

    // Find the new value of FRONT
    if (FRONT == REAR)
    { // Queue has only one element
        FRONT = -1;
        REAR = -1;
    }
    else if (FRONT == N - 1)
    {
        FRONT = 0;
    }
    else
    {
        FRONT = FRONT + 1;
    }
}

int main()
{
    int N ,MAX;
    cout<<"Enter the number of element is Queue=";
    cin>>MAX;
    N=MAX;
    int QUEUE[MAX];
    int FRONT = -1, REAR = -1;

    int ITEM;

    // Example usage
    QINSERT(QUEUE, N, FRONT, REAR, 10);
    QINSERT(QUEUE, N, FRONT, REAR, 20);
    QINSERT(QUEUE, N, FRONT, REAR, 30);

    QDELETE(QUEUE, N, FRONT, REAR, ITEM);
    cout << "Deleted element: " << ITEM << endl;

    return 0;
}
