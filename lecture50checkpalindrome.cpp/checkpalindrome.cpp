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

    void reverse(node* &head, node* &pre, node* curr){

        if( curr == NULL ){
            head = pre;
            return ;
        }

        node* forward = NULL;
         forward = curr -> next;

        curr -> next = pre;
        reverse(head,curr,forward);

      }

    bool checkpalindrome(node* &head){

       node* check = head;
        node* temp = head;
        int cnt = 0;
        
        while ( temp != NULL ){
            cnt++;
            temp = temp -> next;
        }
        temp = NULL;
        if ( cnt % 2 == 0){
            cnt = cnt/2;
        }
        else{
            cnt = (cnt/2) + 1;
        }
        temp = head;
        while ( cnt != 0){
            temp = temp -> next;
            cnt--;
        }
        node * current = temp;
        node*  prev = NULL; 
        reverse(temp,prev,current);
        
        
        while ( temp != NULL ){


            if ( temp -> data  != check -> data ){
                return false;
            }
            else{

                temp = temp -> next;
                check = check -> next;
                
            }
        }
        
        return true;
        
    }


int main(){

node* n1 = new node(7);
node * head = n1;

node* tail = n1;
insertathead(head,9);
insertattail(tail,9);
insertatposition(tail,head,1,18);
insertatposition(tail,head,4,11);
insertatposition(tail,head,6,18);

print (head);
node* pre = NULL;
node* curr = head;
 reverse(head,pre,curr);
print(head);
int ans = checkpalindrome(head);

if ( ans == 1){
    cout << " linked list is in palindrome " << endl;
}
else{
    cout << " not in palindrome ";
}

    

  

}