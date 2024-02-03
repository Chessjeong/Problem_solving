#include <iostream>
#include <algorithm>

using namespace std;

int R,C;
char map[21][21];
int ans;
bool visit[26];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

void DFS(int x, int y, int cnt){
    ans = max(ans, cnt);
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && ny>=0 && nx<R && ny<C){
            if(visit[map[nx][ny]-'A']==false){
                visit[map[nx][ny]-'A']=true;
                DFS(nx,ny, cnt+1);
                visit[map[nx][ny]-'A']=false;
            }
        }
    }
}

int main(){
    cin >> R >> C;
    for(int i=0; i<R;i++){
        cin >> map[i];
    }
    visit[map[0][0]-'A']=true;
    DFS(0,0,1);
    cout << ans <<endl;
    return 0;
}