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
        cout << "NULL" << endl;
    }

    int size() const {
        return count;
    }
};

class SplitLinkedList : public SinglyLinkedList {
public:
    void splitList(SinglyLinkedList& evenList, SinglyLinkedList& oddList) {
        Node* current = head;

        while (current) {
            if (current->data % 2 == 0) {
                evenList.insertAtEnd(current->data);
            }
            else {
                oddList.insertAtEnd(current->data);
            }
            current = current->next;
        }
    }
};

int main() {
    SplitLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    cout << "Original list:" << endl;
    list.display();

    SinglyLinkedList evenList, oddList;
    list.splitList(evenList, oddList);

    cout << "Even list:" << endl;
    evenList.display();

    cout << "Odd list:" << endl;
    oddList.display();

    return 0;
}
