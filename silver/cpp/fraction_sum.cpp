#include <iostream>

using namespace std;

int get_gcd(int a, int b){   
    if (b == 0) return a;
    else {
        int r = a%b;
        return get_gcd(b, r);
    }
}

int main(){
    int a,b,c,d;
    cin >> a >> b;
    cin >> c >> d;
    int numer = a*d + b*c;
    int denom = b*d;
    int integer = numer/denom;
    numer %= denom;
    
    if (numer != 0){
        int gcd = get_gcd(numer, denom);
        numer /= gcd; denom /= gcd;
    }
    else denom = 1;
    numer += integer * denom;
    cout << numer <<" " << denom << endl;

    return 0;
}   