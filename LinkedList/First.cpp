#include "Header.h"

class Node {
    friend class Linkedlist;
private:
    int data;
    Node* nextP;
public:

    Node(int data = 0)
    {
        this->data = data;
        this->nextP = NULL;
    }
};

// Linked list class to
// implement a linked list.
class Linkedlist {
    Node* head;
public:
    // Default constructor
    Linkedlist() {
        head = NULL;
    }

    ~Linkedlist() {
        Node* currentNode = head;
        while (currentNode != NULL)
        {
            Node* next = currentNode->nextP;
            delete currentNode;
            currentNode = next;
        }
    }

    void insertNode(int data)
    {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->nextP != NULL) {
            temp = temp->nextP;
        }

        temp->nextP = newNode;
    }

    void printList()
    {
        Node* temp = head;

        if (head == NULL) {
            cout << "List empty" << endl;
            return;
        }

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->nextP;
        }
    }

    void deleteNode(int nodeOffset) {
        Node* temp1 = head, * temp2 = NULL;
        int ListLen = 0;

        if (head == NULL) {
            cout << "List empty." << endl;
            return;
        }

        while (temp1 != NULL) {
            temp1 = temp1->nextP;
            ListLen++;
        }

        if (ListLen < nodeOffset) {
            cout << "Index out of range"
                << endl;
            return;
        }

        temp1 = head;

        if (nodeOffset == 1) {
            head = head->nextP;
            delete temp1;
            return;
        }

        while (nodeOffset-- > 1) {
            temp2 = temp1;
            temp1 = temp1->nextP;
        }

        temp2->nextP = temp1->nextP;
        delete temp1;
    }
};

void init() {

    Linkedlist list;
    cout << "Init 1: " << endl;

    // Inserting nodes
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);

    cout << "Elements of the list: ";

    // Print the list
    list.printList();
    cout << endl;

    // Delete node at position 2.
    list.deleteNode(2);

    cout << "Elements of the list after deleteNode: ";
    list.printList();
    cout << endl;
}