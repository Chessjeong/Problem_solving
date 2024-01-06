def factorial(n):
    res = 1
    for i in range(1,n+1):
        res*=i
        i+=1
    return res

test_case_num= int(input())
res=[]
for _ in range(test_case_num):
    site_num = list(map(int,input().split()))
    res.append(int(factorial(site_num[1])/(factorial(site_num[0])*factorial(site_num[1]-site_num[0]))))

for result in res:
    print(result)