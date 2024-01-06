def main(num):
    target = num
    res=0
    while(target > 1):
        if target == 3 or target == 2:
            return res+1
        candidates=[]
        candidates.append(target-1)

        if target % 3 == 0:
            candidates.append(target//3)

        if target % 2 == 0:
            candidates.append(target//2)

        ret = [main(candidate) for candidate in candidates if candidate != 1]
        print(ret)
        res = min(ret)
        target = candidates[ret.index(min(ret))]

    return res

        

if __name__ == "__main__":
    res = main(int(input()))
    print(res) 