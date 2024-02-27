#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string input;
    string bomb;
    cin >> input;
    cin >> bomb;
    stack <char> output;
    for(auto iter = input.begin(); iter!= input.end(); iter++){
        output.push(*iter);
        if(output.size()>=bomb.size()){
            string cand;
            for(int i = 0; i < bomb.size(); i++){
                cand += output.top();
                output.pop();
            }
            reverse(cand.begin(),cand.end());
            if(cand != bomb){
                for(int i = 0; i< cand.size(); i++) output.push(cand[i]);
            }
        }
    }
    if(output.empty()) cout << "FRULA" << "\n";
    else{
        string out;
        while(!output.empty()){
            out += output.top();
            output.pop();
        }
        reverse(out.begin(),out.end());
        cout << out << "\n";
    }
}