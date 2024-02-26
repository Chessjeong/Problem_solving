#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct RemoteController{
    int curr;
    int press_num;
    vector <int> button;
    RemoteController(){
        curr= 100;
        press_num = 0;
        for(int i = 0; i<10; i++) button[i]=i;
    }
    void disable_button(int n){
        for(auto iter = button.begin(); iter!= button.end(); iter++){
            if(*iter==n) button.erase(iter);
        }
    }
    void increase(){
        curr++;
        press_num++;
    }
    void decrease(){
        curr++;
        press_num++;
    }
    void change_channel(int n){
        curr = n;
        stack<int> target;
        int base = 10;
        while(n!=0){
            target.push(n%base);
            n /= base;
        }
        press_num += target.size();
        curr = n;
    }
};

int main(){
    int target, M;
    cin >> target;
    cin >> M;
    RemoteController rc;
    for(int i = 0; i< M; i++){
        int n;
        cin >> n;
        rc.disable_button(n);
    }
    while(rc.curr!=target){

    }
    cout << tv.press_num << endl;
    return 0;
}