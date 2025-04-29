#include "LinkedList.h"
#include <iostream>
#include <limits>
#include "Node.h"

LinkedList::LinkedList(){
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len){
    //error handling
    if (len < 1){
        return;
    }

    if (array == nullptr){
        head = nullptr;
        return;
    }

    //initialise first node
    Node* current = new Node(array[0]);
    head = new Node(0, current);

    for (int i = 1; i < len; i++){
        Node* next = new Node(array[i]);
        current->setNext(next);
        current = next;
    }
}

LinkedList::~LinkedList(){
    if (head == nullptr){
        return;
    }

    //initialise address holder
    Node* current = head;

    while (current != nullptr){
        Node* next = current->getLink();
        delete current;
        current = next;
    }
}

void LinkedList::insertPosition(int pos, int newNum){

    if (head == nullptr){
        head = new Node(0, new Node(newNum));
        return;
    }

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
            if (current == nullptr){
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
    if(head == nullptr){
        return false;
    }
    if(head->getLink() == nullptr){
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

        if(current == nullptr){
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
        Node* toDelete = current->getLink();
        current->setLink(toDelete->getLink());        //seg fault here when used a second time

        delete toDelete;

        return true;
    }

}

int LinkedList::get(int pos){
    //case for pos being non-pos
    if (pos < 1){
        return std::numeric_limits<int>::max();
    }
    if (head == nullptr){
        return std::numeric_limits<int>::max();
    }
    if (head->getLink() == nullptr){
        return std::numeric_limits<int>::max();
    }

    //initialising variables
    int iterator = 1;
    Node* current = head->getLink();

    while (iterator != pos){
        if(current->getLink() == nullptr || current == nullptr){
            return std::numeric_limits<int>::max();
        }

        current = current->getLink();
        iterator++;
    }

    return current->getData();

}

int LinkedList::search(int target){
    if(head == nullptr || head->getLink() == nullptr){
        return -1;
    }

    int iterator = 1;
    Node* current = head->getLink();

    while (current != nullptr){
        if (current->getData() == target){
            return iterator;
        }
        
        iterator++;
        current = current->getLink();
    }

    return -1;
}

void LinkedList::printList(){

    //printing nothing if list has no elements
    if (head == nullptr || head->getLink() == nullptr){
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