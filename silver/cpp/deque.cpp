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

class Deque{
    private:
        int size;
        Node* head;
        Node* tail;
    public:
        Deque(){
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
        void push_front(int n){
            Node* curr= new Node(n); 
            curr->next = head;
            if(head!=NULL) head->prev = curr;
            head=curr;
            if(!size) tail=curr;
            size++;
        }
        void push_back(int n){
            Node* curr= new Node(n); 
            curr->prev = tail;
            if(tail!=NULL) tail->next = curr;
            tail=curr;
            if(!size) head=curr;
            size++;
        }
        void pop_front(){
            if(!size){
                cout << -1 <<endl;
                return;
            }
            Node* curr=head;
            head = curr ->next;
            if(head!=NULL) head->prev = NULL;
            size--;
            if(!size) tail = head;
            cout << curr->value << endl;
            delete curr;
        }
        void pop_back(){
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
            if(size) cout << head->value << endl;
            else cout << -1 << endl;
        }
        void back(){
            if(size) cout << tail->value << endl;
            else cout << -1 << endl;
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>> N;
    Deque deque;
    for(int i = 0; i<N; i++){
        string func;
        int n;
        cin >> func;
        if(func == "push_front"){
            cin >> n;
            deque.push_front(n);
        }
        if(func == "push_back"){
            cin >> n;
            deque.push_back(n);
        }
        if(func == "pop_front") deque.pop_front();
        if(func == "pop_back") deque.pop_back();
        if(func == "size") deque.get_size();
        if(func == "empty") deque.empty();
        if(func == "front") deque.front();
        if(func == "back") deque.back();
    }
    return 0;
}