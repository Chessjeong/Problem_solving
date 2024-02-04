#include <iostream>
#include <vector>
// #include <deque>
#include <set>
#include <unordered_map>
// #include <unordered_set>
#include <queue>
// #include <algorithm>

using namespace std;
enum direction {rgt, down, lef, up};
int N , K;


class Snake{
    public:
        direction dir;
        bool alive;
        pair<int, int> head;
        pair<int, int> prev;
        vector<pair <int,int>> edges;

        Snake(){
            dir=rgt;
            alive = true;
            head = make_pair(0,0);
            edges.push_back(make_pair(0,0));
        }

        void rotate(int rot){
            edges.push_back(head);
            dir = static_cast<direction>((dir + rot +4) % 4);            
        }

        bool isalive(){
            int head_x = head.first;
            int head_y = head.second;
            if (head_x > N || head_x < -N || head_y > N || head_y < -N) return false;
        
            vector<pair <int,int>>:: iterator iter;
            for(int i = 0; i < edges.size()-1; i++){
                pair<int,int> curr = edges[i];
                pair<int,int> next = edges[i+1];
                if (i%2==0 && head_y == curr.second && min(curr.first, next.first) <= head_x && max(curr.first, next.first) >= head_x) return false;
                else if (head_x == curr.first && min(curr.second, next.second) <= head_y && max(curr.second, next.second) >= head_y) return false;
            }
            return true;
        }

        void move(){
            int nx = head.first;
            int ny = head.second;
            if(dir == rgt) nx+=1; 
            if(dir == lef) nx-=1;
            if(dir == up) ny+=1;
            if(dir == down) ny-=1;
            head = make_pair(nx,ny);
            alive = isalive();
        }
             
};

    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    
    Snake snake;

    int L;
    cin >> L;
    queue<int> rotate_time;
    queue<int> rot;
    for(int i = 0; i<L; i++){
        int time;
        char rotation;
        cin >> time >> rotation;
        rotate_time.push(time);
        if (rotation == 'R') rot.push(1);
        else if(rotation == 'L') rot.push(-1);
    }
    long long curr=0;
    long long prev_rotate=0;
    while(snake.alive){
        curr++;
        snake.move();
        if(!rotate_time.empty() && curr-prev_rotate == rotate_time.front()){
            snake.rotate(rot.front());
            prev_rotate=curr;
            rotate_time.pop();
            rot.pop();
        }
    }
    cout << curr << endl;
    return 0;
}