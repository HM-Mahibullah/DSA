/* Algorithm 5.10: DELETE (INFO , LINK, START, AVAIL, ITEM)
This algorithm deletes from a linked list the first node N which contains the given ITEM of information.
1. [Use Procedure 5.9 to find the location of N and its preceding node.) Call FINDB(INFO, LINK, START, ITEM, LOC, LOCP)
2. IT LOC=NULL, then: Write: ITEM not in list, and Exit. . (Delete node.] 
3  If LOCP = NULL, then: Set START: LINK[START]. [Deletes first node.] Else:
Set LINK[LOCP] := LINK[LOC].
[End of If structure.] 
4. [Return deleted node to the AVAIL list.] Set LINK[LOC]:= AVAIL and AVAIL := LOC.
5. Exit. */
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

// Function to print the linked list
void PRINT() {
    NODE* Temp = Head;
    while (Temp != nullptr) {
        cout << "Node element = " << Temp->data << ", Node address = " << Temp->next << endl;
        Temp = Temp->next;
    }
}

// Function to free a node by adding it back to the Avail list
void FREENODE(NODE* Temp) {
    Temp->next = Avail;
    Avail = Temp;
}

// Procedure to find the location of the node containing ITEM and its preceding node
void FINDB(int item, NODE*& LOC, NODE*& LOCP) {
  /*   if (Head == nullptr) {  // Step 1: List empty?
        LOC = nullptr;
        LOCP = nullptr;
        return;
    } */

    if (Head->data == item) {  // Step 2: ITEM in the first node?
        LOC = Head;
        LOCP = nullptr;
        return;
    }

    NODE* SAVE = Head;
    NODE* PTR = Head->next;
    while (PTR != nullptr) 
    {  // Step 4: Traverse the list
        if (PTR->data==item) {  // Step 5: ITEM found in current node?
            LOC = PTR;
            LOCP = SAVE;
            return;
        }
        SAVE = PTR;
        PTR = PTR->next;
    }

    LOC = nullptr;  // Step 7: ITEM not found in the list
}

// Function to delete the first node containing the given ITEM
void DELETE(int item) {
    NODE* LOC = nullptr;
    NODE* LOCP = nullptr;

    FINDB(item, LOC, LOCP);  // Step 1: Find the node and its predecessor

    if (LOC == nullptr) {  // Step 2: ITEM not in the list
        cout << "ITEM " << item << " not in list." << endl;
        return;
    }

    if (LOCP == nullptr) {  // Step 3: ITEM is in the first node
        Head = Head->next;
    } else {
        LOCP->next = LOC->next;  // Delete the node by updating the previous node's next pointer
    }

    FREENODE(LOC);  // Step 4: Return the deleted node to the AVAIL list
}

int main() {
    int x, n;
    cout << "Enter number of nodes to create = ";
    cin >> n;
    if (n <= 0) {
        cout << "Number of nodes should be greater than 0." << endl;
        return 0;
    }

    cout << "Enter element for node 1 = ";
    cin >> x;
    NODE* node1 = GETNODE();
    node1->data = x;
    node1->next = nullptr;
    Head = node1;
    NODE* currentNode = node1; // Point node1 which has data and next

    for (int i = 2; i <= n; i++) {
        cout << "Input data elements in Node " << i << " = ";
        cin >> x;
        NODE* newNode = GETNODE();
        newNode->data = x;
        newNode->next = nullptr;
        currentNode->next = newNode;
        currentNode = newNode;
    }

    PRINT();

    int item;
    cout << "Enter the item to delete: ";
    cin >> item;

    DELETE(item);

    cout << "After Deleting Node with item " << item << endl;
    PRINT();
    return 0;
}
