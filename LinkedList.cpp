#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList(){
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len){
    //error handling
    if (len < 1){
        return;
    }

    //initialise first node
    head = new Node(array[0]);

    //initialising current pointer
    Node* current = head;

    for (int i = 1; i < len; i++){
        Node* next = new Node(array[i]);
        current->setNext(next);
        current = next;
    }
}

LinkedList::~LinkedList(){

}

void LinkedList::insertPosition(int pos, int newNum){
    return;
}

bool LinkedList::deletePosition(int pos){
    return 0;
}

int LinkedList::get(int pos){
    return 0;
}

int LinkedList::search(int target){
    return 0;
}

void LinkedList::printList(){

    //printing nothing if list has no elements
    if (head == nullptr){
        return;
    }

    //initialise current node
    Node* current = head;

    std::cout << "[";

    //while loop to print
    while (current->getLink() != nullptr){
        std::cout << current->getData() << " ";
        current = current->getLink();
    }

    //extra one for the loop that doesn't go
    std::cout << current->getData() << "]\n";

    return;
}