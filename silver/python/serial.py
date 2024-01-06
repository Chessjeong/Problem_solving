def sort_rule(serial):
    length=len(serial)
    sum=0
    for char in serial:
        if char.isdigit():
            sum += int(char)

    return (length, sum, serial)

def main():
    num=int(input())
    res=[]
    for _ in range(num):
        res.append(input())

    res=list(sorted(res, key=sort_rule))

    return res

if __name__ == "__main__":
    res = main()
    for serial in res:
        print(serial) 