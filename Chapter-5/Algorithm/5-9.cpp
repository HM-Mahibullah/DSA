/* Procedure 5.9: FINDB(INFO, LINK, START, ITEM, LOC, LOCP)
This procedure finds the location LOC of the first node N which contains ITEM and the location LOCP of the node preceding N. If ITEM does not appear in the list, then the procedure sets LOC = NULL; and if ITEM appears in the first node, then it sets LOCP = NULL.
1. [List empty?] If START = NULL, then: Set LOC:NULL, and LOCP:= NULL, and Return. [End of If structure.]
2. [ITEM in first node?] If INFO[START] = ITEM, then: Set LOC:START and LOCP = NULL, and Return. [End of If structure.]
3. Set SAVE:= START and PTR:= LINK[START]. [Initializes pointers.]
4. Repeat Steps 5 and 6 while PTR NULL.
5. If INFO[PTR] = ITEM, then: Set LOC:= PTR and LOCP:= SAVE, and Return. [End of If structure.]
6. Set SAVE: PTR and PTR := LINK[PTR]. [Updates pointers.] [End of Step 4 loop.]
7. Set LOC:= NULL. [Search unsuccessful.]
8. Return. */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *Head = nullptr;
Node *Avail = nullptr;

void PRINT() {
    Node *Temp = Head;
    while (Temp != nullptr) {
        cout << "Node data: " << Temp->data
             << ", Node address: " << Temp
             << ", Next node address: " << Temp->next << endl;
        Temp = Temp->next;
    }
}
Node *GetNode()
{
if (Avail != nullptr) {
        Node* node = Avail;
        Avail = Avail->next;
        return node; // return pointer type node address
    } else {
        return new Node();
    }
}

void FINDB(int item, Node *&LOC, Node *&LOCP) {
    if (Head == nullptr) {  // Step 1: Check if the list is empty
        LOC = nullptr;
        LOCP = nullptr;
        return;
    }

    if (Head->data == item) {  // Step 2: Check if the item is in the first node
        LOC = Head;
        LOCP = nullptr;
        return;
    }

    Node *SAVE = Head;
    Node *PTR = Head->next;

    while (PTR != nullptr) {  // Step 4: Traverse the list
        if (PTR->data == item) {  // Step 5: Check if the current node contains the item
            LOC = PTR;
            LOCP = SAVE;
            return;
        }
        SAVE = PTR;      // Step 6: Update pointers
        PTR = PTR->next;
    }

    LOC = nullptr;  // Step 7: If the search was unsuccessful
}
 void INSERTELEMENT(Node* &Head,int element)
  {
    Node* Newnode=GetNode();
    Newnode->data=element;
    Newnode->next=nullptr;
    if (Head==nullptr)
    {
      Head=Newnode;
    }
    else
    {
        Node* Temp=Head;
        while (Temp->next!=nullptr)
        {
            Temp=Temp->next;
        }
        Temp->next=Newnode;
        
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
        INSERTELEMENT(Head, element);

    }

    PRINT();

    // Find the location of an element in the linked list.
    cout << "Enter the element to find location = ";
    cin >> element;

    Node *LOC = nullptr, *LOCP = nullptr;
    FINDB(element, LOC, LOCP);  // Call the FINDB function

    if (LOC != nullptr) {
        cout << "Element " << element << " is found at address = " << LOC << endl;
        cout << "This node element is = " << LOC->data << endl;
        if (LOCP != nullptr) {
            cout << "The preceding node address is = " << LOCP << endl;
            cout << "The preceding node element is = " << LOCP->data << endl;
        } else {
            cout << "The element is in the first node, so there is no preceding node." << endl;
        }
    } 
    else {
        cout << "Element " << element << " is not found in the list." << endl;
    }

    return 0;
}
