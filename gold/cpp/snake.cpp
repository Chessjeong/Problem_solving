#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;
enum direction {rgt, down, lef, up};
int N , K;

class Snake{
    public:
        direction dir;
        bool alive;
        deque<pair<int, int>> body;

        Snake(){
            dir=rgt;
            alive = true;
            body.push_back(make_pair(1,1));
        }

        void rotate(int rot){
            dir = static_cast<direction>((dir + rot +4) % 4);
        }

        bool isalive(){
            int head_x = body.back().first;
            int head_y = body.back().second;
            if (head_x > N || head_x < 1 || head_y > N || head_y < 1) return false;
            if(find(body.begin(),body.end()-1,body.back())!= body.end()-1) return false;
            return true;
        }

        void move(){
            int nx = body.back().first;
            int ny = body.back().second;
            if(dir == rgt) ny+=1; 
            if(dir == lef) ny-=1;
            if(dir == up) nx-=1;
            if(dir == down) nx+=1;
            body.push_back(make_pair(nx,ny));
            alive = isalive();
        }
             
};

    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    
    Snake snake;
    cin >> K;
    vector <pair<int,int>> apple_pos;
    for(int i = 0; i<K; i++){
        int x,y;
        cin >> x >> y;
        pair<int,int> apple=make_pair(x,y);
        apple_pos.push_back(apple);
    }

    int L;
    cin >> L;
    queue<int> rotate_time;
    queue<int> rot;
    for(int i = 0; i<L; i++){
        int time;
        char rotation;
        cin >> time >> rotation;
        rotate_time.push(time);
        if (rotation == 'D') rot.push(1);
        else if(rotation == 'L') rot.push(-1);
    }
    int curr=0;
    while(snake.alive){
        curr++;
        snake.move();
        auto iter = find(apple_pos.begin(),apple_pos.end(), snake.body.back());
        if(iter != apple_pos.end()){
            apple_pos.erase(iter);
        }
        else{
            snake.body.pop_front();
        }
        if(!rotate_time.empty() && curr == rotate_time.front()){
            snake.rotate(rot.front());
            rotate_time.pop();
            rot.pop();
        }
    }
    cout << curr<< endl;
    return 0;
}