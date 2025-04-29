#ifndef NODE_H
#define NODE_H

class Node {
    private:
    int data;
    Node* link;

    public:
    Node();
    Node(int newData);
    Node(int newData, Node* newLink);

    int getData();
    void setData(int newData);

    Node* getLink();
    void setLink(Node* newLink);
};

#endif