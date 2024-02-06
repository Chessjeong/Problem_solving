#include <iostream>
#include <string>
#define endl "\n"

using namespace std;

class Node{
    public:
        int value;
        Node* prev;
        Node* next;
        Node(int n) {
            value = n;
        }
};

class Queue{
    private:
        int size;
        Node* head;
        Node* tail;
    public:
        Queue(){
            size = 0;
            head = NULL;
            tail = NULL;
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
            if(head!=NULL) head->prev = curr;
            head=curr;
            if(!size) tail=curr;
            size++;
        }
        void pop(){
            if(!size){
                cout << -1 <<endl;
                return;
            }
            Node* curr=tail;
            tail = curr ->prev;
            if(tail!=NULL) tail->next = NULL;
            size--;
            if(!size) head = tail;
            cout << curr->value << endl;
            delete curr;
        }
        void front(){
            if(size) cout << tail->value << endl;
            else cout << -1 << endl;
        }
        void back(){
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
    Queue queue;
    for(int i = 0; i<N; i++){
        string func;
        int n;
        cin >> func;
        if(func == "push"){
            cin >> n;
            queue.push(n);
        }
        if(func == "pop") queue.pop();
        if(func == "size") queue.get_size();
        if(func == "empty") queue.empty();
        if(func == "front") queue.front();
        if(func == "back") queue.back();
    }
    return 0;
}