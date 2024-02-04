import sys

input=sys.stdin.readline

class Tree:
    def __init__(self, n):
        self.parent=[]
        self.depth=[0]*(n+1)
        for i in range(n+1):
            self.parent.append(i)

    def find(self,x):
        if self.parent[x] is not x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def unite(self,x, y):
        xRoot = self.find(x)
        yRoot = self.find(y)
        if (xRoot != yRoot):
            if (self.depth[xRoot] < self.depth[yRoot]):
                self.parent[xRoot] = yRoot
            elif (self.depth[xRoot] > self.depth[yRoot]):
                self.parent[yRoot] = xRoot
            else:
                self.parent[yRoot] = xRoot
                self.depth[xRoot]+=1

    def same(self,x,y):
        if(self.find(x)==self.find(y)): 
            return True
        else :
            return False
            

def main():

    n, m=map(int,input().split())

    t=Tree(n)
    res=[]

    for i in range(m):
        operation, a, b=map(int,input().split())

        if (operation == 0):
            t.unite(a, b)
        elif (operation == 1):
            if (t.same(a, b)):
                res.append("YES")
            else:
                res.append("NO")

    return res

if __name__ == "__main__":
    res = main()
    for msg in res:
        print(msg)