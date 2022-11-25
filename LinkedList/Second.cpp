#include "Header.h"

class Node {
private:
    int data;
    Node* nextP;

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
    } list;
public:

    Node(int data = 0)
    {
        this->data = data;
        this->nextP = NULL;
    }

    void insertNode(int nr) {
        list.insertNode(nr);
    }

    void deleteNode(int nr) {
        list.deleteNode(nr);
    }

    void printList() {
        list.printList();
    }
};

void init2() {

    Node* nod = new Node;

    cout << "Init 2: " << endl;

    // Inserting nodes
    nod->insertNode(13);
    nod->insertNode(21);
    nod->insertNode(43);
    nod->insertNode(123);
    nod->insertNode(64);
    nod->insertNode(13);
    nod->insertNode(37);

    cout << "Elements of the list: ";

    // Print the list
    nod->printList();
    cout << endl;

    // Delete node at position 6.
    nod->deleteNode(6);

    cout << "Elements of the list deleteNode: ";
    nod->printList();
    cout << endl;

}
