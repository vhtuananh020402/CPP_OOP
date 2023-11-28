#include <iostream>
#include <bits/stdc++.h>


class Node {
    public:
        int data;

        Node *prev;     // previous Node
        Node *next;     // next Node 
};

class DoublyLinkedList { 
    private:    
        Node* head;
    
    public:
        
        DoublyLinkedList();         // constructor, init the head with value NULL
        void insertNode(Node* prevNode, int newData);
        void deleteNode(Node* data);
        void display();
};  


DoublyLinkedList::DoublyLinkedList() {
    this->head = NULL;
}

void DoublyLinkedList::insertNode(Node* prevNode, int newData) {
    if (prevNode == NULL) {
        std::cout << "The given previous node cannot be NULL" << std::endl;
        return ; 
    }

    Node* newNode = new Node();     // create a new Node
    newNode->data = newData;        // set the new data for the new node

    newNode->prev = 
    newNode->next = 
}

void DoublyLinkedList::deleteNode(Node* data) {

}

void DoublyLinkedList::display() {

}


int main() {
    std::cout << "Hello World" << std::endl;
    return 0;
}