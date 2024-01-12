#include <iostream>
#include <string>
#include <vector>
using namespace std;

// - 뒤에 연산을 최대로 한 후 - 해야 최고가 된다.
// + 는 asoociative하기 땜에 +만 있으면 상관이 없다.


int compute_add(string equation){
    int n = equation.find("+");
    if (n != string::npos){
        string back = equation.substr(n+1);
        equation.resize(n);
        int a = stoi(equation);
        int b = compute_add(back);
        return a+b;
    }
    else{
        return stoi(equation);
    }
}

int compute(string input){
    int n = input.find("-");
    if(n != string::npos){
        string back = input.substr(n+1);
        input.resize(n);
        int a = compute_add(input);
        int b = compute(back);
        return a+b;
    }
    else{
        return compute_add(input);
    }
}

int main(){
    string input;
    int res = 0;
    getline(cin, input);
    res -= compute(input);
    int n = input.find("-");
    if(n != string::npos){
        input.resize(n);
    }
    res += 2*compute_add(input);
    cout << res << endl;
}