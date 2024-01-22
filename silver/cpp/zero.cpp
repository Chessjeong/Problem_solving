#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(){
    int K;
    cin >> K;
    vector<int> input;
    for(int i =0; i<K; i++){
        int n;
        cin >> n;
        n == 0 ? input.pop_back() : input.push_back(n);
    }
    int sum = accumulate(input.begin(),input.end(),0);
    cout << sum << endl;
}