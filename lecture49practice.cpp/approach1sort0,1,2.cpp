#include<Iostream>
using namespace std;

class node{
    public: 
    int data;
    node* next;

    node (int data){
        this-> data = data;
        this-> next = NULL;
    }
    ~node(){
        int value = this-> data;
        if(this-> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << " memory is free for node with data "<< value << endl;
    }
};

    void insertathead(node* &head, int d){
        // new node create

        node* temp = new node(d);
        temp -> next = head;
        head = temp;
    }

    void insertattail(node* &tail, int d){
        
        node* n = new node(d);
        tail -> next = n;
        tail = n;
 }
 
    void deletenode(int position, node* &head){

        if(position == 1){
            node* temp = head;
            head = head-> next;
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
          prev -> next = current -> next; 
          current -> next = NULL;
          delete current;
     
        }
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

   node* sortll(node* &head){
       
       int zerocount = 0;
       int onecount = 0;
       int twocount = 0;

       node* temp = head;

       while( temp != NULL ){
         if( temp -> data == 0){
            zerocount ++;
         }
         else if( temp -> data == 1){
            onecount ++;
         }
         else{
            twocount++;
         }
         temp = temp -> next;
       }

       temp = head;
       while( temp != NULL ){
        if( zerocount != 0 ){
            temp -> data = 0;
            zerocount--;
        }
        else if( onecount != 0 ){
            temp -> data = 1;
            onecount--;
        }
        else{
            temp -> data = 2;
            twocount--;
        }
        temp = temp -> next;
       }
       return head;
     
    }


int main(){
//     // create a new node
//    node* n1 = new node(2529);
//     cout << n1 -> data << endl;
//     cout << n1-> next << endl;


//     // head pointer 
//     node* head = n1;
//     print(head);

//    insertathead(head,45);
//    node* tail = n1;
//    print(head);

node* n1 = new node(2);
node * head = n1;

node* tail = n1;
insertathead(head,1);
insertattail(tail,0);
insertatposition(tail,head,1,2);
insertatposition(tail,head,5,0);

cout << " before sorting : ";

print (head);

sortll(head);

cout << " after sorting : ";

print(head);

    

  

}