#include <iostream>

using namespace std;

int main(){
    int N; cin >> N;

    int ans = 0;
    int cnt = 0;
    int temp;

    while(cnt !=N){
        ans++;
        temp = ans;
        while(temp != 0){
            if(temp %1000 == 666){
                cnt++;
                break;
            }
            else temp /= 10;
        }
    }
    cout << ans;
}