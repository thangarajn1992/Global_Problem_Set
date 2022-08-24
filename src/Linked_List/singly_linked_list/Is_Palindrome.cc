#include "Singly_Linked_List.h"

using namespace std;

/* 
    Related Links:
    Leetcode 234 - https://leetcode.com/problems/palindrome-linked-list/
*/
bool
SinglyLinkedList::is_PalindromeIterative()
{
    if(head == nullptr || head->next == nullptr)
        return true;
    
    /* Find the middle element */
    SinglyLinkedListNode *slow = head, *fast = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    SinglyLinkedListNode *mid = slow;

    /* Reverse the second half of list from "mid" node */
    SinglyLinkedListNode *prev = nullptr, *curr = mid, *next = nullptr;
    while(curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    SinglyLinkedListNode* secondHalfHead = prev;
    SinglyLinkedListNode *firstHalfHead = head;

    /* Compare first and second half */
    while(firstHalfHead != nullptr && secondHalfHead != nullptr)
    {
        if(firstHalfHead->data != secondHalfHead->data)
            return false;
        
        firstHalfHead = firstHalfHead->next;
        secondHalfHead = secondHalfHead->next;
    }

    return true;
}


bool 
SinglyLinkedList::is_PalindromeRecursive()
{
    return is_PalindromeRecursiveUtil(&head, head);
}

bool 
SinglyLinkedList::is_PalindromeRecursiveUtil(SinglyLinkedListNode **left, SinglyLinkedListNode *right)
{
    if(right == nullptr)
        return true;
    
    if(is_PalindromeRecursiveUtil(left, right->next))
    {
        if((*left)->data == right->data)
        {
            *left = (*left)->next;
            return true;
        }
    }
    return false;
}