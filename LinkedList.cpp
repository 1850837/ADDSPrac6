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
    Node* current = new Node(array[0]);
    head = new Node(0, current);

    //initialising current pointer

    for (int i = 1; i < len; i++){
        Node* next = new Node(array[i]);
        current->setNext(next);
        current = next;
    }
}

LinkedList::~LinkedList(){
    //initialise address holder
    Node* current = head;

    while (current->getLink() != nullptr){
        Node* next = current->getLink();
        delete current;
        current = next;
    }

    delete current;
}

void LinkedList::insertPosition(int pos, int newNum){

    //case for inputting at the start
    if (pos <= 1){
        Node* a = new Node(newNum, head->getLink());
        head->setLink(a);

        return;
    }

    //all other cases
    else {
        //initialise iterator
        int i = 1;
        Node* current = head->getLink();
        bool breaker = false;

        while (i != (pos - 1)){
            current = current->getLink();
            i++;

            //case for if the pos is greater than length
            if (current->getLink() == nullptr){
                breaker = true;
                break;
            }
        }

        //creating new node for breaker == false
        if (breaker == false){
            Node* a = new Node(newNum, current->getLink());
            current->setLink(a);
        }

        //creating new node for breaker == true
        else if (breaker == true){
            Node* a = new Node(newNum);
            current->setLink(a);
        }
    }

    return;
}

bool LinkedList::deletePosition(int pos){
    //edge cases
    if (pos <= 0){
        return false;
    }

    //initialise variables
    int iterator = 1;
    Node* current = head->getLink();
    bool breaker = false;

    //case for pos == 1
    if (pos == 1){
        head->setLink(current->getLink());      //setting the header to point to item 2
        delete current;     //deleting current
        return true;
    }

    //other cases
    while (iterator != (pos - 1)){
        current = current->getLink();
        iterator++;

        if(current->getLink() == nullptr){
            breaker = true;
            break;
        }
    }

    //case for pos out of bounds
    if (breaker == true){
        return false;
    }

    //actually deleting the node!
    else{

        current->setLink(current->getLink()->getLink());        //seg fault here or line below
        delete current->getLink();

        //std::cout << current->getData() << " " << current->getLink()->getData() << " " << current->getLink()->getLink()->getData() << "\n";

        //need to address the case for pos = 5

        return true;
    }

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
    Node* current = head->getLink();

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