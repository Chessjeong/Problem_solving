#include <iostream>
#include <numeric>
#include <cmath>

using namespace std;

int main(){
    int K, N;
    cin >> K >> N;
    int origin[K];
    for(int i = 0; i< K; i++){
        cin >> origin[i];
    }
    int sum = accumulate(origin, origin+K,0);
    int p = (sum/N)+1;
    int q[K];
    int q_sum=0;
    while(true){
        q_sum = 0;
        for(int i = 0; i < K; i++) q[i] = origin[i]/p;
        q_sum = accumulate(q, q+K, 0);
        if(q_sum >= N) break;
        --p;
    }
    cout << p << endl;
}