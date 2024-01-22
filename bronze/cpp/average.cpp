#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

/*Solving idea: 평균은 선형성을 보존하니까 원래 평균을 구한다음에 max만 구하면 된다.
Time complexity: O(n)*/

int main(){
    int N;
    cin >> N;
    int sum=0;
    int max_score=0;
    float avg;
    for(int i = 0; i<N; ++i){
        int score;
        cin >> score;
        sum+= score;
        if (max_score<score) max_score = score;
    }
    avg = float(sum*100)/(N*max_score);
    cout << avg << endl;
    return 0;
}