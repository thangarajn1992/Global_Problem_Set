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


/* This function inserts the node at the tail end of the list */
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
SinglyLinkedList::InsertAtHead(int data)
{
    SinglyLinkedListNode *node = new SinglyLinkedListNode(data);
    node->next = head;
    head = node;
}

void
SinglyLinkedList::InsertAtIndex(int index, int data)
{
    if(index == 0)
    {
        InsertAtHead(data);
    }
    else
    {
        SinglyLinkedListNode *prev = head;
        for(int currIndex = 0; currIndex < index-1 && prev != nullptr; currIndex++)
        {
            prev = prev->next;
        }
        if(prev != nullptr)
        {
            SinglyLinkedListNode *node = new SinglyLinkedListNode(data);
            node->next = prev->next;
            prev->next = node;   
        }
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

void
SinglyLinkedList::DeleteAtIndex(int index)
{
    if(head == nullptr)
        return;
    
    if(index == 0)
    {
        SinglyLinkedListNode *temp = head;
        head = head->next;
        delete(temp);
    }
    else
    {
        SinglyLinkedListNode *prev = head;
        for(int currIndex = 0; currIndex < index - 1 && prev != nullptr; currIndex++)
        {
            prev = prev->next;
        }
        if(prev != nullptr && prev->next != nullptr)
        {
            SinglyLinkedListNode *temp = prev->next;
            prev->next = prev->next->next;
            delete(temp);
        }

    }
}

int
SinglyLinkedList::getNthNode(int n)
{
    SinglyLinkedListNode *curr = head;

    for(int index = 0; index < n && curr != nullptr; index++)
    {
        curr = curr->next;
    }

    return (curr != nullptr) ? curr->data: -1;
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