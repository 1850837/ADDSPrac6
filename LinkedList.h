#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
    private:
    Node* head;

    public:
    LinkedList();   //constructor
    LinkedList(int* array, int len);    //constructor
    ~LinkedList();  //destructor
    void insertPosition(int pos, int newNum);
    bool deletePosition(int pos);
    int get(int pos);
    int search(int target);
    void printList();
};

#endif