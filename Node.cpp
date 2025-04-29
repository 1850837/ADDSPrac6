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
}

Node* Node::getLink(){
    return link;
}

void Node::setLink(Node* newLink){
    link = newLink;
}