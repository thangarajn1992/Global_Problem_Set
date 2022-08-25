#include "Singly_Linked_List.h"

using namespace std;



/* 
    Check whether there exists a cycle in this linked list.

    Algorithm:
    We can use Floyd's Cycle Finding Algorithm / Rare and Tortoise Algorithm:
        1. Have two pointers at head.
        2. "Slow" pointer moves one node per loop, "fast" pointer moves two nodes per loop.
        3. If these pointers meet at some point, then there exists a loop.

    Related Links:
        Leetcode 141 : https://leetcode.com/problems/linked-list-cycle/
*/
bool
SinglyLinkedList::has_cycle()
{
    SinglyLinkedListNode *slow = head, *fast = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}


/*
    Find the node where the cycle begins, if no cycle exists return nullptr.

    Algorithm:
        1.  We can use same Floyd's Cycle finding algorithm to determine the existence of cycle.
        2.  L1 = Distance between Head and Cycle Start Node.
        3.  L2 = Distance between Cycle Start and Meeting Node.
        4.  C  = Length of the Cycle.
        5.  n  = Number of times the fast ptr looped through the cycle before meeting the slow ptr.
        6.  Distance Travelled by Fast = 2 * (Distance Travelled by Slow)
            L1 + (n * C) + L2 = 2 * (L1 + L2)
            n * C = L1 + L2
            L1 = n * C - L2
            L1 = (n-1)*C + (C - L2)
        7.  It can be concluded that the distance between the head location and entry location is 
            equal to the distance between the meeting location and the entry location along the 
            direction of forward movement.
        8.  Once they meet, move "slow" pointer to head. And move both "fast" and "slow" one node per loop.
        9.  The node at which they meet is the starting node of the cycle.

    Related Links:
        Leetcode 142 : https://leetcode.com/problems/linked-list-cycle-ii/
*/

SinglyLinkedListNode*
SinglyLinkedList::cycle_StartNode()
{
    SinglyLinkedListNode *slow = head, *fast = head;
    int position = -1;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            slow = head;
            position = 0;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            break;
        }
    }
    return (slow == fast)? slow : nullptr;
    
}