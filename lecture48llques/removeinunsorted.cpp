#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    ~node() {
        int value = this->data;
        if (this->next != nullptr) {
            delete this->next;
            this->next = nullptr;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertAtHead(node*& head, node*& tail, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
    if (tail == nullptr) {
        tail = head;
    }
}

void insertAtTail(node*& tail, int d) {
    node* n = new node(d);
    if (tail == nullptr) {
        tail = n;
        return;
    }
    tail->next = n;
    tail = n;
}

void deleteNode(int position, node*& head) {
    if (head == nullptr) return;  // List is empty

    if (position == 1) {
        node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return;
    }

    node* current = head;
    node* prev = nullptr;
    int cnt = 1;

    while (current != nullptr && cnt < position) {
        prev = current;
        current = current->next;
        cnt++;
    }

    if (current == nullptr) return;  // Position is greater than the number of nodes

    prev->next = current->next;
    current->next = nullptr;
    delete current;
}

void print(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(node*& head, node*& tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    node* temp = head;
    int cnt = 1;

    while (temp != nullptr && cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr) {
        insertAtTail(tail, d);
        return;
    }

    node* nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

int lengthOfList(node* head) {
    int cnt = 0;
    node* temp = head;
    while (temp != nullptr) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void removeDuplicates(node*& head) {
    node* current = head;
    while (current != nullptr) {
        node* runner = current;
        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                node* duplicate = runner->next;
                runner->next = runner->next->next;
                duplicate->next = nullptr;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

int main() {
    node* head = nullptr;
    node* tail = nullptr;

    insertAtPosition(head, tail, 1, 7);
    insertAtPosition(head, tail, 2, 3);
    insertAtPosition(head, tail, 3, 5);
    insertAtPosition(head, tail, 4, -6);
    insertAtPosition(head, tail, 5, -9);
    insertAtPosition(head, tail, 6, 11);
    insertAtPosition(head, tail, 7, 3);
    insertAtPosition(head, tail, 8, 5);

    cout << "List before removing duplicates: ";
    print(head);

    int length = lengthOfList(head);
    cout << "Length of the list: " << length << endl;

    removeDuplicates(head);

    cout << "List after removing duplicates: ";
    print(head);

    return 0;
}
