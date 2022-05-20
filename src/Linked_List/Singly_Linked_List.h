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

    SinglyLinkedListNode *getHead() { return head; }
    void setHead(SinglyLinkedListNode *listNode) { head = listNode; }

    // Utils
    void print();

    // Operations
    void Insert(int value);
};
#endif