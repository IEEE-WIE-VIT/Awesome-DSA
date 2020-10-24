n, W = [int(i) for i in input().split()]
lst=[]
value=0
if W==0:
    print(0)
    quit()
for _ in range(n):
    v,wt=[int(i) for i in input().split()]
    if v==0:
        continue
    lst.append((v,wt))
lst.sort(key=lambda x: x[0]/x[1],reverse=True)
for v,wt in lst:
    if W==0:
        break
    a=min(wt,W)
    #print(a)
    value=value+a*v/wt
    #print(v)
    #w[i]=w[i]-a
    W=W-a
print(value)
    
