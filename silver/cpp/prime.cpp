#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, N;
    cin >> M >> N;
    for(int i = M; i <= N; i++){
        if(i == 1) continue;
        bool is_prime = true;
        for(int j = 2; j*j <= i; j++){
            if(i % j == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime) cout << i << '\n';
    }
}