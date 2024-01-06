#include <iostream>

using namespace std;

int log(int n){
    int res = 0;
    while(n > 0){
        n /= 10;
        res++;
    }
    return res;
}

int decomposesum(int n){
    int res=n;
    while(n > 0){
        res += n%10;
        n /= 10;
    }
    
    return res;
}

int main(){
    int target; 
    cin >> target;
    int res = 0;
    int logn = log(target);
    for (int i = target - 9*logn; i<target; i++){
        if(decomposesum(i)==target){
            res = i;
            break;
        }
    }
    cout << res << endl;
}