#include <iostream>
#include <algorithm>

using namespace std;
bool cmp(string a, string b){
    bool res = (a.length()== b.length()) ? (a<b) : (a.length()< b.length());
    return res;
}
string input[20000];
int main(){
    int test_n;
    cin >> test_n;
    for (int i =0 ; i< test_n; i++){
        cin >> input[i];
    }

    sort(input,input+test_n,cmp);
    for (int i = 0; i<test_n; i++){
        if(input[i]== input[i-1]) continue;
        cout << input[i] << '\n';
    }
    return 0;

}