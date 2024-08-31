// reverse linked list
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
       this-> data = data;
       this-> next = NULL;
    }
};
void insertathead(node* &head, int d){
    node* temp = new node(d);
    temp -> next = head;
    head = temp;
}

void insertattail(node* &tail, int d){
        node* n = new node(d);
        tail -> next = n;
        tail = n;
 }

 void print(node* &head){

       node* temp = head;
        while( temp != NULL){
            cout << temp -> data;
            temp = temp -> next;
            cout << " ";
        }
        cout << endl;
    }
    void insertatposition(node* &tail, node* &head, int position, int d){

        if( position == 1){
            insertathead(head,d);
            return ;
        }
        node* temp = head;
        int cnt = 1;
        while( cnt <  position - 1){
            temp = temp-> next;
            cnt++;

        }
        if(temp -> next == NULL){
            insertattail(tail,d);
            return ;
        }
        node* nodetobeinsert = new node(d);
         nodetobeinsert -> next = temp -> next;
         temp -> next =  nodetobeinsert;
    }
  node*  reverselist(node* &head){
        node* curr = head;
        node* prev = NULL;
        node* forw = NULL;
        while(curr != NULL){
            forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
}
return prev;
    }
    int main(){
        node* head = new node(5); 
        node* tail = head;
        insertatposition(tail,head,2,12);
        insertatposition(tail,head,2,7);
        insertatposition(tail,head,2,99);
        cout << " original list is : ";
        print(head);
        head = reverselist(head);
        cout << "reversed list is : ";
        print(head);
        
        
    }