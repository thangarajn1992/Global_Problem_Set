#include "Singly_Linked_List.h"

using namespace std;

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

SinglyLinkedList::SinglyLinkedList(vector<int> data)
{
    if(data.size() == 0)
    {
        head = nullptr;
        return;
    }
    head = new SinglyLinkedListNode(data[0]);
    SinglyLinkedListNode *curr = head;
    for(int index = 1; index < data.size(); index++)
    {
        curr->next = new SinglyLinkedListNode(data[index]);
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

vector<int>
SinglyLinkedList::print()
{
    SinglyLinkedListNode *curr = head;
    vector<int> result;
    while(curr != nullptr)
    {
        result.push_back(curr->data);
        curr = curr->next;
    }
    return result;
}