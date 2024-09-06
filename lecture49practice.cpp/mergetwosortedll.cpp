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
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertathead(node*& head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertattail(node*& tail, int d) {
    node* n = new node(d);
    tail->next = n;
    tail = n;
}

void deletenode(int position, node*& head) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

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
    while (cnt < position && current != NULL) {
        prev = current;
        current = current->next;
        cnt++;
    }

    if (current == NULL) {
        cout << "Position out of bounds!" << endl;
        return;
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

void insertatposition(node*& tail, node*& head, int position, int d) {
    if (position == 1) {
        insertathead(head, d);
        if (head->next == NULL) { // If the list was empty, update tail
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
        cout << "Position out of bounds!" << endl;
        return;
    }

    if (temp->next == NULL) {
        insertattail(tail, d);
        return;
    }

    node* nodetobeinsert = new node(d);
    nodetobeinsert->next = temp->next;
    temp->next = nodetobeinsert;
}
node* mergetwo(node* &head1, node* &head2){
  
 
 node* mergehead = NULL;
 node* mergetail = NULL;

 if ( head1 -> data < head2 -> data ){
     
     mergehead = head1;
     head1 = head1 -> next;

 }
 else{
    mergehead = head2;
    head2 = head2 -> next;
 }
 mergetail = mergehead;

 while ( head1 != NULL && head2 != NULL ){

    if ( head1 -> data <= head2 -> data ){
    
     mergetail -> next = head1;
     head1 = head1 -> next;
}
else{

    mergetail -> next = head2;
    head2 = head2 -> next;
}
  mergetail = mergetail -> next;

  if ( head1  != NULL ){
     mergetail -> next = head1;
     
  }
  else{
    mergetail -> next = head2;
   
  }

 }

 return mergehead;

      
}
      
int main() {
    node* n1 = new node(8);
    node* n2 = new node(6);
    node* head = n1;
    node* head2 = n2;

    node* tail = n1;
    node* tail2 = n2;

    insertathead(head, 5);
    insertattail(tail, 9);
    insertatposition(tail, head, 1, 2);
    insertatposition(tail, head, 5, 11);

    insertathead(head2, 4);
    insertattail(tail2, 7);
    insertatposition(tail2, head2, 1, 3);
    insertatposition(tail2, head2, 5, 10);

    cout << "List 1: ";
    print(head);
    cout << "List 2: ";
    print(head2);

    // Cleanup

    cout << " after merging two lists : ";

    node* h = mergetwo( head , head2);

    print( h);
   

    return 0;
}
