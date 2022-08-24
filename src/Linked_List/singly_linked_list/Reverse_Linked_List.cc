#include "Singly_Linked_List.h"

using namespace std;

/*
    Related Links:
    Leetcode 206 - https://leetcode.com/problems/reverse-linked-list/
*/
void
SinglyLinkedList::reverseIterative()
{
    SinglyLinkedListNode *prev = nullptr, *curr = head, *next = nullptr;

    while(curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
 }

 SinglyLinkedListNode*
 SinglyLinkedList::reverseRecursive(SinglyLinkedListNode *node)
 {
    if(node == nullptr || node->next == nullptr)
        return node;
    
    SinglyLinkedListNode *curr = reverseRecursive(node->next);
    node->next->next = node;
    node->next = nullptr;

    return curr;
 }