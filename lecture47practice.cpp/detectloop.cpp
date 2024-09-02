#include<Iostream>
#include<map>
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

    bool detectloop(node* &head){
        if( head == NULL ){
            return false;
        }
        map< node*,bool> visited;
        node* temp = head;

        while( temp != NULL){
            if ( visited[temp] == 1){
                return 1;
            }
            else{
                visited[temp] = true;
                temp = temp -> next;
            }
        }
        return 0;

    }


int main(){

node* n1 = new node(7);
node * head = n1;

node* tail = n1;
insertathead(head,9);
insertattail(tail,99);
insertatposition(tail,head,1,18);
insertatposition(tail,head,5,45);

tail -> next = head -> next;

if( detectloop(head)){
    cout << " loop is present "<< endl;
}
else{
    cout << " loop is absent " << endl;
}

    

  

}