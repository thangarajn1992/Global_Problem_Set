#include "Singly_Linked_List.h"

using namespace std;

void
SinglyLinkedList::print()
{
    SinglyLinkedListNode *curr = head;
    cout << "[ ";
    while(curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "]" << endl;
}

SinglyLinkedList::SinglyLinkedList(SinglyLinkedListNode *node)
{
    if(node == nullptr)
    {
        head = nullptr;
        return;
    }
    
    head = new SinglyLinkedListNode(node->data);
    SinglyLinkedListNode *curr = head;

    while(node->next != nullptr)
    {
        node = node->next;
        curr->next = new SinglyLinkedListNode(node->data);
        curr = curr->next;
    }
}

void
SinglyLinkedList::Insert(int data)
{
    if(head == nullptr)
    {
        head = new SinglyLinkedListNode(data);
    }
    else
    {
        SinglyLinkedListNode *curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        
        curr->next = new SinglyLinkedListNode(data);
    }
}

void
SinglyLinkedList::Delete(int data)
{
    if(head == nullptr)
    {
        cout << "Error: List is Empty" << endl;
        return;
    }

    SinglyLinkedListNode *prev = nullptr, *curr = head;
    while(curr != nullptr)
    {
        if(curr->data == data)
        {
            /* If head is to be deleted */
            if(prev == nullptr)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            cout << "Deleted " << curr->data << endl;
            delete(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}