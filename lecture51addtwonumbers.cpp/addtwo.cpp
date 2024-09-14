#include <iostream>
#include <vector>
#include<algorithm>
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
    if (position == 1) {
        if (head == NULL) return;  // Empty list case
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    } else {
        node* current = head;
        node* prev = NULL;
        int cnt = 1;
        while (cnt < position && current != NULL) {
            prev = current;
            current = current->next;
            cnt++;
        }
        if (current == NULL) return;  // Position out of bounds
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
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
        if (head->next == NULL) {  // If the list was previously empty
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
    if (temp == NULL) return;  // Position out of bounds
    if (temp->next == NULL) {
        insertattail(tail, d);
        return;
    }
    node* nodetobeinsert = new node(d);
    nodetobeinsert->next = temp->next;
    temp->next = nodetobeinsert;
}

void convert(node* head, vector<int>& arr) {
    node* temp = head;
    while (temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }
}

void add(const vector<int>& arr1, const vector<int>& arr2, vector<int>& arr3) {
    int index1 = arr1.size() - 1;
    int index2 = arr2.size() - 1;
    int carry = 0;

    while (index1 >= 0 && index2 >= 0) {
        int sum = arr1[index1] + arr2[index2] + carry;
        carry = sum / 10;
        sum = sum % 10;
        arr3.push_back(sum);
        index1--;
        index2--;
    }

    while (index1 >= 0) {
        int sum = arr1[index1] + carry;
        carry = sum / 10;
        sum = sum % 10;
        arr3.push_back(sum);
        index1--;
    }

    while (index2 >= 0) {
        int sum = arr2[index2] + carry;
        carry = sum / 10;
        sum = sum % 10;
        arr3.push_back(sum);
        index2--;
    }

    if (carry > 0) {
        arr3.push_back(carry);
    }

    reverse(arr3.begin(), arr3.end());  
}

// convert array again to a linked list

node* convert2(vector<int> arr){
    int i = 0;
    node* temp = new node(arr[i]);
    node* head = temp; 
    node* tail = temp;

    for( i = 1; i < arr.size(); i++ ){
        insertatposition(tail,head,(i+1),arr[i]);
    }
    return head;
}




int main() {
    node* n1 = new node(7);
    node* n2 = new node(7);

    node* head = n1;
    node* head2 = n2;

    node* tail = n1;
    node* tail2 = n2;

    insertathead(head, 9);
    insertattail(tail, 9);
    insertatposition(tail, head, 1, 1);
    insertatposition(tail, head, 5, 4);

    insertatposition(tail2, head2, 1, 9);
    insertatposition(tail2, head2, 2, 2);  // Corrected position to 2

    vector<int> arr;
    vector<int> arr2;
    convert(head, arr);
    convert(head2, arr2);

    vector<int> arr3;

    add(arr, arr2, arr3);

    for (int i = 0; i < arr3.size(); i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    node* h = convert2(arr3);

    print(h);


    return 0;
}
