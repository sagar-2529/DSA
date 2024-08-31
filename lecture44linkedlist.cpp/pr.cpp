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
        // Destructor to handle memory cleanup
        cout << "Memory is freed for node with data " << data << endl;
    }
};

void insertnode(node*& tail, int element, int d) {
    // For empty list
    if (tail == nullptr) {
        node* temp = new node(d);
        tail = temp;
        temp->next = temp;
    } else {
        // For non-empty list
        node* curr = tail;
        while (curr->next != tail && curr->data != element) {
            curr = curr->next;
        }
        if (curr->data == element) {
            node* temp = new node(d);
            temp->next = curr->next;
            curr->next = temp;
            // If inserting after the tail node
            if (tail == curr) {
                tail = temp;
            }
        } else {
            cout << "Element not found in the list." << endl;
        }
    }
}

void print(node* tail) {
    if (tail == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

void deletenode(node*& tail, int element) {
    if (tail == nullptr) {
        cout << "List is empty. Please check again." << endl;
        return;
    }

    node* curr = tail->next;
    node* prev = tail;

    // Check if the node to be deleted is the only node
    if (curr == tail && curr->data == element) {
        delete curr;
        tail = nullptr;
        return;
    }

    // Find the node to delete
    do {
        if (curr->data == element) {
            prev->next = curr->next;
            if (tail == curr) {
                tail = prev;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);

    cout << "Element not found in the list." << endl;
}

int main() {
    node* tail = nullptr;

    // Test insertion and deletion
    insertnode(tail, 5, 3);
    print(tail);

    deletenode(tail, 3);
    print(tail);

    // Additional testing
    insertnode(tail, 5, 7);
    insertnode(tail, 7, 9);
    insertnode(tail, 9, 18);
    insertnode(tail, 7, 11);
    print(tail);

    deletenode(tail, 7);
    print(tail);

    return 0;
}
