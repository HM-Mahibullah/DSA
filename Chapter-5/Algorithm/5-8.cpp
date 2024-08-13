/* 
Algorithm 5.8: DEL(INFO, LINK, START, AVAIL, LOC, LOCP)
This algorithm deletes the node N with location LOC. LOCP is the location of the node which precedes
 Nor, when N is the first node, LOCP = NULL. 1. If LOCP = NULL, then:
Set START:= LINK[START]. [Deletes first node.]
Set LINK[LOCP]:= LINK[LOC]. [Deletes node N.]
Else:
[End of If structure.] 
2. [Return deleted node to the AVAIL list.) Set LINK[LOC]:= AVAIL and AVAIL: LOC.
3. Exit. */
#include <iostream>
using namespace std;

struct NODE {
    int data;
    NODE* next;
};

NODE* Head = nullptr;
NODE* Avail = nullptr;

// Function to get a new node, either from the Avail list or by allocating new memory
NODE* GETNODE() {
    if (Avail != nullptr) {
        NODE* node = Avail;
        Avail = Avail->next;
        return node; // return pointer type node address
    } else {
        return new NODE();
    }
}

// Function to insert a new element into the list
void InsertElement(NODE*& Head, int element) {
    NODE* newnode = GETNODE();
    newnode->data = element;
    newnode->next = nullptr;
    
    if (Head == nullptr) {
        Head = newnode;
    } else 
    {
        NODE* Temp = Head;
        while (Temp->next != nullptr) {
            Temp = Temp->next;
        }
        Temp->next = newnode;
    }
}

// Function to print the linked list
void PRINT() {
    NODE* Temp = Head;
    while (Temp != nullptr) {
        cout << "Node element=" << Temp->data << " and Node address=" << Temp->next << endl;
        Temp = Temp->next;
    }
}

// Function to free a node by adding it back to the Avail list
void FREENODE(NODE* Temp) 
{
    Temp->next = Avail;
    Avail = Temp;
}

// Function to delete the first node in the list
void DELETEFIRST() {
    if (Head != nullptr) {
        NODE* Temp = Head;
        Head = Head->next;
        FREENODE(Temp);
    }
}
// Function to get the node at a specific location (n)
NODE* GETLOCNODE(int n) {
    NODE* Temp = Head;
    int count = 1;
    while (Temp != nullptr && count < n) {
        Temp = Temp->next;
        count++;
        /*     

Linked lists are typically 1-based indexed, meaning the first node is at position 1, the second node is
 at position 2, and so on.
Consider a list with nodes A (1), B (2), and C (3), and you want to find the node at position 2.

Using count < position:

Initial: Temp points to node A, count is 1.
First iteration: Temp moves to node B, count is incremented to 2.
Condition count < position becomes false (2 < 2 is false), so the loop exits.
Temp correctly points to node B, which is at position 2. */
    }
    return (count == n) ? Temp : nullptr;
}

// Function to delete a node at a specific location (position)
void DELETE(int position) {
    if (Head == nullptr) {
        cout << "The list is empty. Cannot delete." << endl;
        return;
    }

    if (position == 1) 
    {
        DELETEFIRST(); // Delete the first node if the position is 1
    } else {
        NODE* LOCP = GETLOCNODE(position - 1);
        if (LOCP == nullptr || LOCP->next == nullptr) {
            cout << "Invalid position. Node does not exist." << endl;
            return;
        }
        NODE* LOC = LOCP->next;
        LOCP->next = LOC->next; // Delete node N by updating the link of the previous node
        FREENODE(LOC);          // Return the deleted node to the AVAIL list
    }
}
int main() {
    int n, element;
    cout << "Enter number of nodes to create: ";
    cin >> n;
    if (n <= 0) {
        cout << "Number of nodes should be greater than 0." << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        cout << "Enter the element for node " << i << ": ";
        cin >> element;
        InsertElement(Head, element);
    }

    cout << "Linked List:" << endl;
    PRINT();
    
    int position;
    cout << "Enter the position of the node to delete: ";
    cin >> position;
    
    DELETE(position);

    cout << "After deleting node at position " << position << ":" << endl;
    PRINT();

    return 0;
}
/* Enter number of nodes to create: 3
Enter the element for node 1: 6
Enter the element for node 2: 5
Enter the element for node 3: 4
Linked List:
Node element=6 and Node address=0x8a16d0
Node element=5 and Node address=0x8a6f70
Node element=4 and Node address=0
Enter the position of the node to delete: 3
After deleting node at position 3:
Node element=6 and Node address=0x8a16d0
Node element=5 and Node address=0 */