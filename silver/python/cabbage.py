
def main():
    test_n=int(input())
    worms=[]
    for _ in range(test_n):
        cond = list(map(int, input().split()))
        cabbage=[]
        worm=0
        for __ in range(cond[2]):
            cabbage.append(tuple(map(int, input().split())))
        while(len(cabbage)>0):
            worm += 1
            count = 1
            new=[]
            start = cabbage.pop()
            new.append(start)
            while(count > 0):
                count = 0
                candidates=[]
                for point in new:
                    candidates.append((point[0],point[1]+1))
                    candidates.append((point[0],point[1]-1))
                    candidates.append((point[0]-1,point[1]))
                    candidates.append((point[0]+1,point[1]))
                new=[]
                for point in candidates:
                    if point in cabbage:
                        count+=1
                        cabbage.remove(point)
                        new.append(point)

        worms.append(worm)      



    return worms

if __name__ == "__main__":
    res = main()
    for worm in res:
        print(worm) 