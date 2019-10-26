import math


def mul(a,b):
    
    count=0
    if(a<0):
        a=a*-1
        count+=1
    if(b<0):
        b=b*-1
        count+=1
    a=f'{a:.6f}'
    b=f'{b:.6f}'
    if(a.find(".")!=-1):
            d1=len(a)-a.find(".")-1
    else:
            d1=0

    if(b.find(".")!=-1):
            d2=len(b)-b.find(".")-1
    else:
            d2=0
    d=d1+d2
    a1=a.replace(".","")
    b1=b.replace(".","")
    a1=int(a1)
    b1=int(b1)
    r=0
    for i in range(min(a1,b1)):
            r=r+max(a1,b1)
    r=str(r)
    r=list(r)
    while(len(r)<d):
            r.insert(0,'0')
    r.insert(len(r)-d,'.')
    if(count==1):
        r.insert(0,"-")
    r=''.join(r)
    return float(r)

def funb(n):
    if(n==0):
        return 1
    else:
        f=0
        for i in range(0,n):
            f=f-mul(a[i],funb(n-i-1))
        return f
    
print("Enter value of sin x")
z=float(input())
x=math.asin(z)
print("Check upto number of terms (complexity)?, enter n: ")
n=int(input())
a=[]
for i in range(1,n):
    t=mul((-1)**i,math.factorial(mul(2,i)+1)**(-1))
    a.append(t)

ans=0
for i in range(0,n):
    ans=ans+mul(funb(i),(x**(mul(2,i)-1)))

print("The value of cosec x is " +str(ans))

    



    
    
    
    
