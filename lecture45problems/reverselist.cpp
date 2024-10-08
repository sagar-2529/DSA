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
void reverse(node* &head, node* &curr, node* &prev){

        if( curr == NULL){
            head = prev;
            return ;
        }
        node* forward = NULL;
        forward = curr -> next;
      
        reverse(head,forward,curr);
          curr -> next = prev;

     }
  
    
    int main(){
        node* head = new node(5); 
        node* tail = head;
        insertatposition(tail,head,2,12);
        insertatposition(tail,head,2,7);
        insertatposition(tail,head,2,99);
        cout << " original list is : ";
        print(head);
        node* prev  = NULL;
        node* curr = head;
        reverse(head,curr,prev);
        cout << "reversed list is : ";
        print(head);
        
        
    }