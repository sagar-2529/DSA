// middle of lists
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
    int lengthofstring(node* &head){
        node* temp = head;
        int cnt = 0;
        while(temp != NULL){
            temp = temp-> next;
            cnt++;
        }
        return cnt;
    }
    node* middleoflist(node* head){
        node* temp = head;
       int a = lengthofstring(head);
       int cnt = (a/2)+1;
       int test = 1;
          while(test != cnt){
            temp = temp -> next;
            test++;
            }
       return temp;
    

       }
       int main(){
        node* head = new node(7);
        node* tail = head;
        insertatposition(tail,head,2,8);
        insertatposition(tail,head,2,9);
        insertatposition(tail,head,2,10);
        insertatposition(tail,head,2,25);
        insertatposition(tail,head,2,25);
        print(head);
        node* ans = middleoflist(head);
        cout << " middle of node is : "<< ans -> data;
       }
     

    