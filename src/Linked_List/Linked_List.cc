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
            cout << "Head Loc: " << SLL.getHead() << endl;
            SLL.print();
            cout << endl;

            cout << "Copying One List to Another List: " << endl;
            SinglyLinkedList SLLCopy(SLL.getHead());
            cout << "Head Loc: " << SLLCopy.getHead() << endl;
            SLLCopy.print();
            cout << endl;

            int data1= 30, data2 = 10;
            SLLCopy.print();
            cout << "Delete Node " << data1 << endl;
            SLLCopy.Delete(data1);
            SLLCopy.print();
            cout << "Delete Head Node " << data2 << endl;
            SLLCopy.Delete(data2);
            SLLCopy.print();
            cout << endl;

            vector<int> data_vec = {100, 200, 300, 400, 500, 600};
            cout << "Creating Linked List with vector " << data_vec << endl;
            SinglyLinkedList SLLVector(data_vec);
            SLLVector.print();
            cout << endl;

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