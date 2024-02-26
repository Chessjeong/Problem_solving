#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    pair<pair<int,int>, string> p[N];
    for(int i = 0; i < N; i++){
        cin >> p[i].first.first >> p[i].second;
        p[i].first.second = i;
    }
    sort(p, p+N);
    for(int i = 0; i < N; i++){
        cout << p[i].first.first << " " << p[i].second << '\n';
    }
}