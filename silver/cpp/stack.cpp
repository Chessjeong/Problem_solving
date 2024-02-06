#include <iostream>
#include <string>
#define endl "\n"

using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node(int n) {
            value = n;
        }
};

class Stack{
    private:
        int size;
        Node* head;
    public:
        Stack(){
            size = 0;
            head = NULL;
        }
        void get_size(){
            cout << size << endl;
        }
        void empty(){
            if(size) cout << 0 << endl;
            else cout << 1 << endl;
        }
        void push(int n){
            Node* curr= new Node(n); 
            curr->next = head;
            head=curr;
            size++;
        }
        void pop(){
            if(!size){
                cout << -1 <<endl;
                return;
            }
            Node* curr=head;
            head = curr ->next;
            size--;
            cout << curr->value << endl;
            delete curr;
        }
        void top(){
            if(size) cout << head->value << endl;
            else cout << -1 << endl;
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>> N;
    Stack stack;
    for(int i = 0; i<N; i++){
        string func;
        int n;
        cin >> func;
        if(func == "push"){
            cin >> n;
            stack.push(n);
        }
        if(func == "pop") stack.pop();
        if(func == "size") stack.get_size();
        if(func == "empty") stack.empty();
        if(func == "top") stack.top();
    }
    return 0;
}