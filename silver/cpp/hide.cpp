#include <iostream>
#include <vector>
using namespace std;

/*
Idea sketch: target과 2*current의 비교가 중요한듯
y-2x=k
if k = 1 -> 2배 하고 +1하면됨
k = 2 -> +1하고 2배
k = 3 
*/
int time(int current, int target){
    int min = 0;
    int diff = target - current;
    if(diff < 1) return (-1*diff);
    if(diff == 1) return 1;
    if(diff == current) return 1;
}


int main(){
    int current, target;
    cin >> current >> target;
    cout << time(current, target) << endl;

}

