#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(7);
    cout << " front of q is : " << q.front() << endl;
    q.push(1);
    cout << " front of q is : " << q.front() << endl;
    q.push(9);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}