#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
        Node* parent;
        Node* left;
        Node* right;
        int value;
        Node(int n){
            value(n);
            parent=NULL;
            left=NULL;
            right=NULL;
        }        
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<Node> sequence;
    vector<int> max_parent;
    vector<pair<int,int>> output;
    int N , M;
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        int num;
        cin >> num;
        min_parent[i]=num;
        max_parent[i]=num;
    }
    for(int i = 0; i<M; i++){
        int a, b;
        cin >> a >> b;

    }

}