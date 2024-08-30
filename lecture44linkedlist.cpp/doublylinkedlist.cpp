#include<iostream>
using namespace std;

class node{
    public : 
    int data;
   node* next;
   node* prev;

   node(int d){
     this -> data = d;
     this -> prev = NULL;
     this -> next = NULL;
}
   ~node(){
    int val = this-> data;
    if(next!= NULL){
        delete next;
        next = NULL;
    }
    cout << " memory is free for node with data "<<  val << endl;
   }
};
 void print(node* &head){
    if ( head -> next == NULL){
         cout << head-> data;
    }
    else{
    node* temp = head;
    int cnt = 1;
    while( temp!= NULL ){
        cout << temp -> data << "  ";
        temp = temp-> next;
        cnt ++;
    }
    cout << endl;

   }
 }
   void insertathead(node* &tail, node* &head,int d){
    if(head == NULL){
     node* temp = new node(d);
     head = temp;
     tail = temp;
    }
    else{
     node* temp = new node(d);
     temp -> next = head;
     head -> prev = temp;
     head = temp;
   }
   }

   void insertattail(node* &tail, node* &head , int d){
    if(tail == NULL){
        node* temp = new node(d);
        tail = temp;
        head = temp;

    }
    else{
       node* temp = new node(d);
       temp -> prev = tail;
       tail -> next = temp;
       tail = temp;
   }
   }

   void insertatposition(node* &tail, node* &head, int pos, int d){

    if (pos == 1){
       insertathead(tail,head,d);
       return;
    }
        node* temp = head;
    
    int cnt = 1;
    while(cnt < pos - 1){
        temp = temp -> next;
        cnt ++;
    }

    if(temp -> next == NULL){
        insertattail(tail,head,d);
        return;
    }
    node* nodetobeinserted = new node(d);
    nodetobeinserted -> next = temp -> next;
    temp -> next -> prev =  nodetobeinserted;
    temp -> next = nodetobeinserted;
    nodetobeinserted -> prev = temp;



   }
   void deletenode(int position, node* &head){

        if(position == 1){
            node* temp = head;
            head = head-> next;
            temp -> next -> prev = NULL;
            temp -> next = NULL;
            delete temp;
            return ;
        }
        else{
            node* current = head;
            node* prev = NULL;
            int cnt = 1;
            while(cnt < position){
                prev = current;
                current = current-> next;
                cnt++;
            }
              current -> prev = NULL;
          prev -> next = current -> next; 
          current -> next = NULL;
        
          delete current;
     
        }
    }

   int getlength(node* &head){
    node* temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp-> next;

    }
    return length;

   }

int main(){
    
    node* head = NULL;
    node* tail = NULL;
    insertathead(tail,head,69);
    insertatposition(tail,head,2,98);
    insertathead(tail,head,27);
    insertatposition(tail,head,2,34);
    print(head);
    deletenode(3,head);
    print(head);
    deletenode(3,head);
     print(head);
      deletenode(1,head);
          print(head);
 
    

    return 0;
}