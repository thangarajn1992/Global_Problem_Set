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
SinglyLinkedList::Insert(int value)
{
    if(head == nullptr)
    {
        head = new SinglyLinkedListNode(value);
    }
    else
    {
        SinglyLinkedListNode *curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        
        curr->next = new SinglyLinkedListNode(value);
    }
}