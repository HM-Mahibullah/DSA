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

int main()
{
    int MAX, N;
    cout << "Enter the number of elment is queues=";
    cin >> MAX;
    int N = MAX;
    int QUEUE[MAX];
    int FRONT = -1, REAR = -1;

    // Example usage
    QINSERT(QUEUE, N, FRONT, REAR, 10);
    QINSERT(QUEUE, N, FRONT, REAR, 20);
    QINSERT(QUEUE, N, FRONT, REAR, 30);

    cout << "Inserted 10, 20, 30 into the queue." << endl;

    return 0;
}
