#include <iostream>
#include <vector>

using namespace std;

int match_target(vector <int> seq, int target){
    int cnt = 0;
    for (int i = 0; i< seq.size(); i++){
        int e = seq.back();
        seq.pop_back();
        cnt += match_target(seq, target-e);
    }
}

int main(){
    int N , target;
    cin >> N >> target;
    int cnt = 0;
    vector <int> seq(N);
    for (int i = 0; i<N; i++){
        int n;
        cin >> n;
        seq.push_back(n)
    }
    for (int i = 0; i< N; i++){
        int e = seq.back();
        seq.pop_back();
        cnt += match_target(seq, target-e);
    } 
    cout << cnt << endl;
}