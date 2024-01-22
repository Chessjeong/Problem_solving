#include <iostream>
using namespace std;

int compute_gcd(int a,int b){
    int q = a/b;
    int r = a%b;
    if(r == 0) return b;
    else return compute_gcd(b,r);
}

int compute_lcm(int a, int b){
    return a*b/compute_gcd(a,b);
}

int main(){
    int a, b;
    cin >> a >> b;
    if(a<b){
        int tmp ;
        tmp = a;
        a = b;
        b = tmp;
    }
    int gcd = compute_gcd(a,b);
    int lcm = compute_lcm(a,b);
    cout << gcd << endl;
    cout << lcm << endl;

}