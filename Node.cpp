#include "Node.h"

Node::Node(){
    data = 0;
    link = nullptr;
}

Node::Node(int newData){
    data = newData;
    link = nullptr;
}

Node::Node(int newData, Node* newLink){
    data = newData;
    link = newLink;
}

int Node::getData(){
    return data;
}

void Node::setData(int newData){
    data = newData;
    return;
}

Node* Node::getLink(){
    return link;
}

void Node::setLink(Node* newLink){
    link = newLink;
    return;
}

void Node::setNext(Node* newNode){
    link = newNode->getLink();
    return;
}