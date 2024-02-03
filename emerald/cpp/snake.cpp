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
enum type{start, end};
int N , K;

int encode(int n, int t) {
    int mask = (t & 1) << 31;
    int msb = (n >> 31) & 1;
    n &= ~(1 << 31);
    n |= (msb << 30); 
    n |= mask;
    return n;
}

void decode(int encoded, int &n, type &t) {
    t = (encoded >> 31) & 1; // 인코딩된 값의 MSB를 플래그로 추출
    int msb = (encoded >> 30) & 1; // 30번째 비트의 값을 원래 MSB로 사용
    n = encoded & ~(3 << 30); // 상위 2비트(플래그 비트와 이전 MSB)를 클리어
    n |= (msb << 31); // 복원된 MSB를 설정
}


class Snake{
    public:
        direction dir;
        bool alive;
        pair<int, int> head;
        pair<int, int> prev;
        // vector<pair <int,int>> edges;
        unordered_map<int,set<int>> vertical;
        unordered_map<int,set<int>> horizon;

        Snake(){
            dir=rgt;
            alive = true;
            head = make_pair(0,0);
            // prev = make_pair(0,0);
            vertical[head.first].insert(encode(head.second,start));
            horizon[head.second].insert(encode(head.first,end));
            // edges.push_back(make_pair(0,0));
        }

        void rotate(int rot){
            // edges.push_back(head);
            if(dir == rgt || dir == lef) {
                vertical[head.first].insert(encode(head.second,start));
                horizon[head.second].insert(encode(head.first,end));
            }
            if(dir == down || dir == up) {
                horizon[head.second].insert(encode(head.first,start))
                vertical[head.first].insert(encode(head.second,end));
            }
            prev = head;
            dir = static_cast<direction>((dir + rot +4) % 4);            
        }

        bool isalive(){
            int head_x = head.first;
            int head_y = head.second;
            if (head_x > N || head_x < -N || head_y > N || head_y < -N) return false;
            set<int>::iterator iter;
            if ((dir== rgt || dir == lef)&&vertical.count(head_x)){
                for(iter=vertical[head_x].begin(); iter!= vertical[head_x].end(); iter++){
                    int n;
                    type t;
                    decode(*iter, n, t);
                }
            }
            if ((dir== up || dir == down)&&horizon.count(head_y)){
                for(iter=horizon[head_y].begin(); iter!= horizon[head_y].end(); iter++){
                    
                }
            }
            return true;

        
            // vector<pair <int,int>>:: iterator iter;
            // for(int i = 0; i < edges.size()-1; i++){
            //     pair<int,int> curr = edges[i];
            //     pair<int,int> next = edges[i+1];
            //     if (i%2==0 && head_y == curr.second && min(curr.first, next.first) <= head_x && max(curr.first, next.first) >= head_x) return false;
            //     else if (head_x == curr.first && min(curr.second, next.second) <= head_y && max(curr.second, next.second) >= head_y) return false;
            // }
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