#include<Iostream>
using namespace std;

class node{

    public :
    int data;
    node* next;

    node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~node(){
        int val = this-> data;
        if(next!= NULL){
            delete next;
            this -> next = NULL;
        }
        cout << " memory is free for node with data "<< val << endl;
    }

};
void insertnode(node* &tail, int element, int d){
    
    // for empty list
    if( tail == NULL ){
          node* temp = new node(d);
        tail = temp;
        temp -> next = temp;
}
  
   else{
    // for non empty list
        node* curr = tail;
        while(element != curr -> data){
            curr = curr-> next;

        }
        // element found s pointer is on it
        node* temp = new node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
        }
}
void print(node* &tail){

   node* temp = tail;
    if(temp == NULL) {
        cout << "List is empty" << endl;
        return;
    }
   
   do{
   
    cout << temp -> data << " ";
    temp = temp -> next;
   }
   while(tail != temp);
   cout << endl;

}



void deletenode(node* tail,int element){
    if (tail == NULL){
        cout << " list is empty please check again "<< endl;
    }
    else{
    node* prev = tail;
    node* curr = prev -> next;
    while(curr -> data != element){
        prev = curr;
        curr = curr -> next;

    }
    prev -> next = curr -> next;
    // for one node linked list
    if (curr == prev){
       
        tail = NULL;
       
    }
    else if(tail == curr){
        tail = prev;
    }
    curr -> next = NULL;
    delete curr;

}
}

int main(){

    node* tail = NULL;
    insertnode(tail,5,3);
    print(tail);
    deletenode(tail,3);
    print(tail);
   
}

