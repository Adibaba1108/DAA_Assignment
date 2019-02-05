#include <iostream>
using namespace std;
 
int sieve(int a[],int max,int n)
{
    bool prime[max];
    int i,j;
    for(i=0;i<max;i++)
    prime[i]=true;
    prime[0]=false;
    prime[1]=false;
 
    for(i=2;i*i<=max;i++)
    {
        if(prime[i]==true)
        {
            for(j=2*i;j<max;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    int min=1000000;
    for(i=0;i<n;i++)
    {
        if(prime[a[i]]==true)
        {
            if(a[i]<min)
            min=a[i];
        }
    }
    return min;
}
int main()
{
    int n,i;
    cin>>n;
    int a[n];
    int max=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(max<=a[i])
        max=a[i];
    }
    int ans=sieve(a,max,i);
    if(ans!=1000000)
    printf("%d is the smallest prime number in the given array.",ans);
    else
    printf("No prime number in the given array.");
    return 0;
}
