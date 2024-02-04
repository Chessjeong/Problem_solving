#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool deac(int a, int b) return a > b;

void printer(){
    int N, target;
    cin >> N >> M;
    vector<int> importances;
    for(int i = 0; i< N; i++){
        int importance;
        cin >> importance;
        importances.push_back(importance);
    }
    int target = importances[M];
    vector<int>::iterator iter;
    int max_num = 0;
    int max_idx = -1;
    int ans = 0;
    for(iter=importances.begin(); iter!= importances.end(); iter++){
        int cur = *iter;
        if(cur>max_num){
            max_num = cur;
            max_idx = iter - importances.begin()
        }
        if(cur > target) ans++;
        if (cur == )
    }
}

int main(){
    int test_num;
    cin >> test_num;
    for(int i = 0; i<test_num; i++) printer();
    return 0;
}