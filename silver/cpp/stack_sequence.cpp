#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;

stack<int> sequence;
int cnt = 1;
vector<char> res;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    bool flag = true;
    for(int i=0; i<n; ++i){
        int element;
        cin >> element;
        while(cnt<=element){
            sequence.push(cnt);
            res.push_back('+');
            cnt++;
        }
        if(sequence.top() == element){
            sequence.pop();
            res.push_back('-');
        }
        else{
            flag = false;
        }
    }
    if(flag){
        for(int i= 0; i < res.size(); ++i) cout << res[i] << endl;
    }
    else{
        cout << "NO" <<endl;
    }
}