
def main():
    M,N = list(map(int,input().split()))
    A=[]
    B=[]
    res=0

    if min(M,N) < 3:
        res = -1
        return res

    for _ in range(M):
        row = [int(num) for num in input()]
        A.append(row)
    
    for _ in range(M):
        row = [int(num) for num in input()]
        B.append(row)

    

    

if __name__ == "__main__":
    print(main())  