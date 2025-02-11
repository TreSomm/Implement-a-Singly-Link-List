#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteFirst() {
        if (!head) return;

        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
    }

    void deleteLast() {
        if (!head) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    void deleteInterior(int value) {
        if (!head) return;

        if (head->data == value) {
            deleteFirst();
            return;
        }

        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            if (temp == tail) tail = current;
            delete temp;
        }
    }

    void display() const {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList list;

    cout << "Forward List:" << endl;
    list.insertAtBeginning(5);
    list.insertAtBeginning(4);
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);
    list.display();

    cout << "Deleting the first node:" << endl;
    list.deleteFirst();
    list.display();

    cout << "Deleting the last node:" << endl;
    list.deleteLast();
    list.display();

    cout << "Deleting the middle node:" << endl;
    list.deleteInterior(3);
    list.display();

    LinkedList list2;
    cout << "Backward list:" << endl;
    list2.insertAtEnd(5);
    list2.insertAtEnd(4);
    list2.insertAtEnd(3);
    list2.insertAtEnd(2);
    list2.insertAtEnd(1);
    list2.display();

    cout << "Deleting the first node:" << endl;
    list2.deleteFirst();
    list2.display();

    cout << "Deleting the last node:" << endl;
    list2.deleteLast();
    list2.display();

    cout << "Deleting the middle node:" << endl;
    list2.deleteInterior(3);
    list2.display();

    return 0;
}
