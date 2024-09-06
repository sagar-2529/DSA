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
    void insertatail(node* &curr, node* &t){

        t -> next = curr;
        t = curr;
    }

    node* sort( node* &head ){

        node* zerohead = new node(-1);
        node* zerotail = zerohead;
        node* onehead = new node(-1);
        node* onetail = onehead;
        node* twohead = new node(-1);
        node* twotail = twohead;

        node* curr = head;

        while( curr != NULL ){
             
             int value = curr-> data;

             if ( value == 0 ){
                insertatail(curr,zerotail);
             }

             else if( value == 1){
                insertatail(curr,onetail);
             }
             else{
                insertatail(curr,twotail);
             }
             curr = curr -> next;
        }
        if( onehead -> next != NULL ){
        zerotail -> next = onehead -> next;

    }
    else{
        zerotail -> next = twohead -> next; 
    }
    onetail -> next = twohead -> next;
    twotail -> next = NULL;

    head = zerohead -> next;

    delete(zerohead);
    delete(onehead);
    delete(twohead);

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
insertatposition(tail,head,1,1);
insertatposition(tail,head,5,2);

print (head);

node* h = sort(head);

print(h);

    

  

}