#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> data;

    // Pushing elements into the queue
    data.push(1);
    data.push(2);
    data.push(3);

    //Popping the front element (delete 1)
    data.pop();

    // Pushing more elements into the queue
    data.push(4); // front will be 2, rear will be 4
    data.push(5);

    // Access the front element of the queue
    cout << data.front() << endl;  // Should print 2

    // Access the rear element of the queue
    cout << data.back() << endl;   // Should print 5

    return 0;
}
