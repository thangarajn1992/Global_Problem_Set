#include "All_Linked_List.h"

typedef enum linkedListType{
    LINKED_LIST_SINGLE = 1,
    LINKED_LIST_DOUBLE = 2,
    LINKED_LIST_CIRCULAR
}linkedListType_t;

void linkedListMain()
{
    unsigned int type;
    cout << "Enter the Linked List Type: " << endl;
    cout << "1. Singly Linked List" << endl;
    cout << "2. Doubly Linked List" << endl;
    cout << "3. Circular Linked List" << endl;
    cin >> type;

    switch(static_cast<linkedListType_t>(type))
    {
        case LINKED_LIST_SINGLE:
        {

            SinglyLinkedList SLL;
            cout << "Inserting data into Linked List: " << endl;
            cout << "Inserting 10, 20, 30, 40, 50, 60, 70.." << endl;
            SLL.Insert(10);
            SLL.Insert(20);
            SLL.Insert(30);
            SLL.Insert(40);
            SLL.Insert(50);
            SLL.Insert(60);
            SLL.Insert(70);
            cout << SLL.print();
            cout << endl;
            
            cout << "Inserting 5 at Index 0" << endl;
            SLL.InsertAtHead(5);
            cout << SLL.print();
            cout << "Inserting 65 at Index 7" << endl;
            SLL.InsertAtIndex(7, 65);
            cout << SLL.print();
            cout << endl;

            cout << "Deleting at Index 5" << endl;
            SLL.DeleteAtIndex(5);
            cout << SLL.print();
            cout << endl;
            
            cout << "Copying One List to Another List: " << endl;
            SinglyLinkedList SLLCopy(SLL.getHead());
            cout << "Old List Head Loc: " << SLL.getHead() << endl;
            cout << "New List Head Loc: " << SLLCopy.getHead() << endl;
            cout << SLLCopy.print();
            cout << endl;

            int data1= 30, data2 = 10;
            SLLCopy.print();
            cout << "Delete Node " << data1 << endl;
            SLLCopy.Delete(data1);
            cout << "List After deleting Node " << data1 << " is " << SLLCopy.print();
            cout << "Delete Head Node " << data2 << endl;
            SLLCopy.Delete(data2);
            cout << "List After deleting Head Node " << data2 << "is " << SLLCopy.print();
            cout << endl;

            {
                vector<int> data_vec = {100, 200, 300, 400, 500, 600};
                cout << "Creating Linked List with vector " << data_vec << endl;
                SinglyLinkedList SLLVector(data_vec);
                cout << "Created List " << SLLVector.print();
                cout << endl;
            }

            {
                cout << "Reverse a Linked List" << endl;
                vector<int> data_vec = {100, 200, 300, 400, 500, 600};
                SinglyLinkedList SLLVector(data_vec); 
                cout << "Given List: " << SLLVector.print();
                
                SLLVector.reverseIterative();
                cout << "Reversed List (Iterative): " << SLLVector.print();
                SLLVector.setHead(SLLVector.reverseRecursive(SLLVector.getHead()));
                cout << "Again Reversed List(Recursive): " << SLLVector.print();
                cout << endl;
            }
            
            {
                cout << "Check whether Linked List is Palindrome or not" << endl;
                vector<int> pal_data = {156, 45, 43, 45, 156};
                vector<int> nopal_data = {15, 34, 24, 22, 15};
                SinglyLinkedList SLLPalindrome(pal_data);
                SinglyLinkedList SLLNoPalindrome(nopal_data);

                cout << "Linked List: " << SLLPalindrome.print();
                cout << "Is Palindrome (Iterative): " << SLLPalindrome.is_PalindromeIterative() << endl;
                cout << "Linked List: " << SLLNoPalindrome.print();
                cout << "Is Palindrome (Recursive): " << SLLNoPalindrome.is_PalindromeRecursive() << endl;
                cout << endl;
            }

            {
                cout << "Check Whether Linked List has cycle" << endl;
                vector<int> cycle_data = {14, 54, 22, 52, 11};
                SinglyLinkedList SLLNoCycle(cycle_data);
                /* Creating cycle in linked list at index 1*/
                SinglyLinkedList SLLCycle(cycle_data);
                SinglyLinkedListNode *temp = SLLCycle.getHead();
                temp = temp->next; // moving to index 1 to get its address
                SinglyLinkedListNode *curr;
                for( curr = SLLCycle.getHead(); curr->next != nullptr; curr = curr->next);
                curr->next = temp; // creating a cycle from tail to index 1 node.
                cout << "Has Cycle: " << SLLCycle.has_cycle() << endl;

                cout << "Linked List: " << SLLNoCycle.print();
                cout << "Has Cycle: " << SLLNoCycle.has_cycle() << endl;
                cout << endl;
            }

            {
                cout << "Find the starting node of cycle in linked list if it exists" << endl;
                vector<int> cycle_data = {14, 54, 22, 52, 11};
                SinglyLinkedList SLLNoCycle(cycle_data);
                /* Creating cycle in linked list at index 1*/
                SinglyLinkedList SLLCycle(cycle_data);
                SinglyLinkedListNode *temp = SLLCycle.getHead();
                temp = temp->next; // moving to index 1 to get its address
                SinglyLinkedListNode *curr;
                for(curr = SLLCycle.getHead(); curr->next != nullptr; curr = curr->next);
                curr->next = temp; // creating a cycle from tail to index 1 node.

                SinglyLinkedListNode *startNode = SLLCycle.cycle_StartNode();
                cout << "Cycle Start Node: ";
                if(startNode != nullptr)
                    cout << startNode->data << endl;
                else
                    cout << "nullptr" << endl;

                startNode = SLLNoCycle.cycle_StartNode();
                cout << "Cycle Start Node: ";
                if(startNode != nullptr)
                    cout << startNode->data << endl;
                else
                    cout << "nullptr" << endl;

            }

            break;
        }
        case LINKED_LIST_DOUBLE:
        {
            break;
        }
        case LINKED_LIST_CIRCULAR:
        {
            break;
        }
        default:
            cout << "Error: Invalid Linked List option selected" << endl;
    }
}