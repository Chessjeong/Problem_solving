import sys

input=sys.stdin.readline
direction=['east','south','west','north']
score=[]
score_map=[]

class Dice():
    def __init__(self):
        self.pos_x=0
        self.pos_y=0
        self.bottom = 6
        self.front = 5
        self.right = 3
        self.dir = 0

    def move(self):
        if(direction[self.dir] == 'east'): 
            self.pos_y+=1
            self.bottom, self.right = self.right, 7-self.bottom
        elif(direction[self.dir] == 'south'):
            self.pos_x+=1
            self.bottom, self.front = self.front, 7-self.bottom
        elif(direction[self.dir] == 'west'):
            self.pos_y-=1
            self.bottom, self.right = 7-self.right, self.bottom
        else:
            self.pos_x-=1
            self.bottom, self.front = 7-self.front, self.bottom
        if(self.pos_x < 0 or self.pos_x >= len(score_map)):
            self.changedir(2)
            self.move()
            self.move()
        if(self.pos_y < 0 or self.pos_y >= len(score_map[0])):
            self.changedir(2)
            self.move()
            self.move()
        return
    
    def changedir(self,n):
        self.dir+=n
        self.dir%=4
        return
    
def BFS(x, y, visited=None):
    if visited is None:
        visited = set()
    visited.add((x, y))
    
    res = {(x, y)}
    cand = [(x-1, y), (x+1, y), (x, y-1), (x, y+1)]
    
    for point in cand:
        if point[0] < 0 or point[0] >= len(score_map) or point[1] < 0 or point[1] >= len(score_map[0]):
            continue
        if point in visited:
            continue
        if score_map[point[0]][point[1]] == score_map[x][y]:
            res |= BFS(point[0], point[1], visited)
    
    return res

    
def calculate_score(x,y):
    res=score_map[x][y]
    cluster={(x,y)}
    cluster= BFS(x,y)
    for point in cluster:
        score[point[0]][point[1]]=score_map[x][y]*len(cluster)
    return        


def main():
    N, M , K = map(int, input().split())
    dice = Dice()
    res = 0
    for _ in range(N):
        score_map.append(list(map(int, input().split())))
        score.append([0]*M)

    for _ in range(K):

        dice.move()
        if(score[dice.pos_x][dice.pos_y]==0):
            calculate_score(dice.pos_x, dice.pos_y)
        if(dice.bottom > score_map[dice.pos_x][dice.pos_y]):
            dice.changedir(1)
        elif(dice.bottom < score_map[dice.pos_x][dice.pos_y]):
            dice.changedir(-1)
        res+=score[dice.pos_x][dice.pos_y]
    print(res)


if __name__ =='__main__':
    main()