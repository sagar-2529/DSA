#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~node() {
        int value = this->data;
        if (this->next != NULL) {
            delete this->next;
            this->next = NULL;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertAtHead(node*& head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(node*& tail, int d) {
    node* n = new node(d);
    if (tail != NULL) {
        tail->next = n;
        tail = n;
    } else {
        tail = n;
    }
}

void deleteNode(int position, node*& head) {
    if (position == 1) {
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    node* current = head;
    node* prev = NULL;
    int cnt = 1;
    while (cnt < position) {
        prev = current;
        current = current->next;
        cnt++;
    }
    prev->next = current->next;
    current->next = NULL;
    delete current;
}

void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(node*& tail, node*& head, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        if (tail == NULL) {
            tail = head;
        }
        return;
    }
    node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL) {
        return; // Position is out of bounds
    }
    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }
    node* nodeToBeInserted = new node(d);
    nodeToBeInserted->next = temp->next;
    temp->next = nodeToBeInserted;
}

node* floydsAlgo(node* head) {
    if (head == NULL) return NULL;

    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow; // Intersection point
        }
    }
    return NULL; // No cycle
}

node* getCycleStart(node* intersection, node* head) {
    if (intersection == NULL) return NULL;

    node* slow = head;
    node* fast = intersection;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow; // Start of the cycle
}

int main() {
    node* n1 = new node(7);
    node* head = n1;
    node* tail = n1;

    insertAtHead(head, 9);
    insertAtTail(tail, 99);
    insertAtPosition(tail, head, 1, 18);
    insertAtPosition(tail, head, 5, 45);

    // Create a cycle
    tail->next = head->next; // Point tail to one of the nodes in the middle

    node* intersection = floydsAlgo(head);
    if (intersection != NULL) {
        node* cycleStart = getCycleStart(intersection, head);
        if (cycleStart != NULL) {
            cout << "Cycle starts at node with data: " << cycleStart->data << endl;
        } else {
            cout << "No cycle start found." << endl;
        }
    } else {
        cout << "No cycle detected." << endl;
    }

    // Cleanup
    delete head; // This will delete the entire list

    return 0;
}
