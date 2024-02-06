#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
        Node* parent;
        Node* left;
        Node* right;
        int value;
        Node(int n=0){
            value(n);
            parent=NULL;
            left=NULL;
            right=NULL;
        }        
};

Node min(Node a, Node b){
    Node ret;
    if(a.value <= b.value){
        ret.left
    }
}

int find_min(vector<Node> sequence){
    if(sequence.size() < 2) return sequence[0].value;
    int middle = sequence.size()/2
    vector<Node> front(sequence.begin(),sequence.begin()+middle);
    vector<Node> back(sequence.begin()+middle,sequence.end())
}

int find_max(vector<Node> sequence){

}


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
        Tree input(num);
        sequence.push_back(input);
    }
    for(int i = 0; i<M; i++){
        int a, b;
        cin >> a >> b;
        vector<Node> partial(sequence.begin()+a-1,sequence.begin()+b);
        int min = find_min(partial);
        int max = find_max(partial);
        output.push_back(make_pair(min,max));
    }
    for(int i = 0; i<output.size(); i++) cout << output[i].first << " " << output[i].second << endl;
}