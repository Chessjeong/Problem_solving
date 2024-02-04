#include <iostream>
#include <vector>
#include <queue>

using namespace std;
enum direction {rgt, down, lef, up};
int N , K;
int abs(int n){
    int res;
    return res = (n>0 ? n : -n);
}

class Snake{
    public:
        direction dir;
        bool alive;
        pair<int, int> head;
        pair<int, int> prev;
        vector<pair <int,int>> edges;
        queue<int> rotate_time;
        queue<int> rot;
        long long life;

        Snake(){
            dir=rgt;
            alive = true;
            head = make_pair(0,0);
            edges.push_back(make_pair(0,0));
            life = 0;
        }

        void rotate(int rot){
            edges.push_back(head);
            dir = static_cast<direction>((dir + rot +4) % 4);
            prev=head;           
        }

        bool isalive(){
            int head_x = head.first;
            int head_y = head.second;
            vector<pair <int,int>>:: iterator iter;
            int basis;
            int vert=0x7fffffff;
            int hori=0x7fffffff;
            for( basis = 0; basis < edges.size()-1; basis+=1){
                pair<int,int> curr = edges[basis];
                pair<int,int> next = edges[basis+1];
                if(prev == next) continue;
                if (curr.second>=min(prev.second, head.second) && curr.second <=max(prev.second, head.second) && min(curr.first, next.first) <= head_x && max(curr.first, next.first) >= head_x){
                    if(vert>abs(prev.second-curr.second))
                        vert= abs(prev.second-curr.second);
                }
                if (curr.first >=min(prev.first, head.first) && curr.first <=max(prev.first, head.first) && min(curr.second, next.second) <= head_y && max(curr.second, next.second) >= head_y) {
                    if(hori > abs(prev.first-curr.first))
                        hori = abs(prev.first-curr.first);
                }
            }
            if(head_x > N){
                if(hori>N+1-prev.first)
                    hori = N+1-prev.first;
            }
            if(head_x < -N){
                if(hori>N+1+prev.first)
                    hori=N+1+prev.first;
            }
            if (head_y > N) {
                if(vert>N+1-prev.second)
                    vert = N+1-prev.second;
            }
            if (head_y < -N){
                if(vert>N+1+prev.second)
                    vert=N+1+prev.second; 
            }
            if(min(hori, vert) != 0x7fffffff){
                if(min(hori, vert)!=0)
                    life+=min(hori,vert);
                else life+=max(hori,vert);
                return false;
            }
            return true;
        }

        void move(){
            int nx = head.first;
            int ny = head.second;
            if(!rotate_time.empty()){
                int d = rotate_time.front();
                rotate_time.pop();
                if(dir == rgt) nx+=d; 
                if(dir == lef) nx-=d;
                if(dir == up) ny+=d;
                if(dir == down) ny-=d;
                head = make_pair(nx,ny);
                alive = isalive();
                if(alive) life+= d;
                // cout << "Life: "<< life <<endl;
                int rotation = rot.front();
                rot.pop();
                rotate(rotation);
            }
            else {
                if(dir == rgt) nx=N+1; 
                if(dir == lef) nx=-N-1;
                if(dir == up) ny=N+1;
                if(dir == down) ny=-N-1;
                head=make_pair(nx,ny);
                alive=isalive();
            }
            
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
    for(int i = 0; i<L; i++){
        int time;
        char rotation;
        cin >> time >> rotation;
        snake.rotate_time.push(time);
        if (rotation == 'R') snake.rot.push(1);
        else if(rotation == 'L') snake.rot.push(-1);
    }
    while(snake.alive){
        snake.move();
    }
    cout << snake.life << endl;
    return 0;
}