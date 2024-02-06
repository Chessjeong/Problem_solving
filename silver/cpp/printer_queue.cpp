#include <iostream>
#include <deque>

using namespace std;

int main(){
    int test_num;
    cin >> test_num;
    for(int i=0; i<test_num; i++){
        int N, target, target_imp=0;
        cin >> N >> target;
        deque <pair<int,int>> imp;
        for(int i=0; i<N; i++){
            int importance;
            cin >> importance;
            if(i==target) target_imp=importance;
            imp.push_back(make_pair(importance,i));
        }
        int ans=0;
        while(true){
            bool printable=true;
            pair<int,int> curr = imp.front();
            imp.pop_front();
            for(int i =0; i<imp.size(); i++){
                if(imp[i].first>curr.first){
                    printable=false;
                    break;
                }
            }
            if(printable){
                ans++;
                if(curr.second==target) break;
            }            
            else imp.push_back(curr);
        }
        cout << ans << endl;
    }
    return 0;
}