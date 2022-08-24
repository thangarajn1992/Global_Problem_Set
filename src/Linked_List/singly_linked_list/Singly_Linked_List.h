#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "Linked_List.h"

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int val) : data{val}, next(nullptr) {}
};

class SinglyLinkedList{
private:
    SinglyLinkedListNode *head;

public:
    SinglyLinkedList() {head = nullptr;}
    SinglyLinkedList(SinglyLinkedListNode *node);
    SinglyLinkedList(vector<int> data);

    SinglyLinkedListNode *getHead() { return head; }
    void setHead(SinglyLinkedListNode *listNode) { head = listNode; }

    // Utils
    vector<int> print();

    // Operations
    void Insert(int value);
    void Delete(int value);

    // Reverse given Linked List
    void reverseIterative();
    SinglyLinkedListNode* reverseRecursive(SinglyLinkedListNode *node);
};
#endif