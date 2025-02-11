#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
protected:
    Node* head;
    Node* tail;
    int count;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    ~SinglyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        count = 0;
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
        count++;
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
        count++;
    }

    void deleteFirst() {
        if (!head) return;

        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
        count--;
    }

    void deleteLast() {
        if (!head) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            count--;
            return;
        }

        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = nullptr;
        count--;
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
            count--;
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

    int size() const {
        return count;
    }

private:
    void reversePrint(Node* node) const {
        if (!node) return;
        reversePrint(node->next);
        cout << node->data << " -> ";
    }

public:
    void reversePrint() const {
        reversePrint(head);
        cout << "nullptr" << endl;
    }
};

int main() {
    SinglyLinkedList list;

    for (int i = 1; i <= 10; ++i) {
        list.insertAtEnd(i);
    }

    cout << "List in regular order:" << endl;
    list.display();

    cout << "List in reverse order:" << endl;
    list.reversePrint();

    return 0;
}
