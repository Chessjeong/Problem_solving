#include <iostream>
#include <string>

using namespace std;

bool isgroupword(string word){
    int len = word.length();
    string unique="";
    for(int i=0; i<len; i++){
        if(i==0) unique.push_back(word[i]);
        if(i> 0 && word[i] != word[i-1]){
            if(unique.find(word[i]) != string::npos) return false;
            else {
                unique.push_back(word[i]);
            }            
        }
    }
    return true;
}

int main(){
    int N; 
    cin >> N;
    int cnt = 0;
    for(int i =0 ; i<N; i++ ){
        string word;
        cin >> word;
        if(isgroupword(word)) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}