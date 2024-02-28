#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
int main(){
    int test_num;
    cin>> test_num;
    vector<int> ans;
    for (int i = 0; i < test_num; i++){
        int k , n;
        cin >> k;
        cin >> n;
        vector<vector<int>> people;
        vector<int>v;
        for(int j = 0; j<n+1; j++){
            v.push_back(j);
        }
        people.push_back(v);
        for(int j = 1; j<k+1; j++){
            vector<int>v;
            for(int m =0; m<n+1; m++){
                int sum = accumulate(people[j-1].begin(),people[j-1].begin()+m+1,0);
                v.push_back(sum);
            }
            people.push_back(v);
        }
    ans.push_back(people[k][n]);
    }
    for(int i = 0; i<test_num; i++) cout << ans[i] << endl;    
}