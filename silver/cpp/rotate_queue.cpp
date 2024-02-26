#include <iostream>
#define endl "\n"

using namespace std;

class Node{
    public:
        int value;
        Node* prev;
        Node* next;
        Node(int n){
            value=n;
            prev =NULL;
            next =NULL;
        }

};

class cQueue{
    private:
        Node* head;
        int size;
    public:
        void push(int n){
            Node* curr = new Node(n);
            if(head!=NULL) {
                curr->next=head;
                head->prev->next=curr;
                curr->prev=head->prev;
                head->prev=curr;
            }
            else{
                curr->next=curr;
                curr->prev=curr;
            }
            head=curr; 
            size++;         
        }
        void pop(){
            Node* curr=head;
            head=curr->next;
            size--;
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            delete curr;
        }
        void right(){
            head=head->next;
        }
        void left(){
            head=head->prev;
        }
        int front(){
            return head->value;
        }
        int get_size() {
            return size;
        }
        bool empty(){
            if(size>0) return false;
            return true;
        }
        int distance(int target){
            Node* old_head=head;
            int d_r=0, d_l=0;
            while(!this->empty()&&this->front()!=target){
                this->right();
                d_r++;
            }
            head=old_head;
            while(!this->empty()&&this->front()!=target){
                this->left();
                d_l++;
            }
            return min(d_l,d_r);
        }
        cQueue(int n){
            head=NULL;
            size=n;
            for(int i=0; i<n; i++){
                this->push(n-i);
            }
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    cQueue q(N);
    int input[M];
    for(int i =0; i<M; i++) cin>>input[i];
    int ans = 0;
    int pop_num = 0;
    int target_idx=0;
    while(pop_num<M){
        int target=input[target_idx];
        ans+=q.distance(target);
        q.pop();
        pop_num++;
        target_idx++;
    }
    cout << ans << endl;
}