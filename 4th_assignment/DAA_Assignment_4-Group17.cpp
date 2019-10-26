#include<bits/stdc++.h>
using namespace std;
int fun(int n,int count)
		{
			if(n==1){
				
				return count;
				
				}
			else if(n%2==0){
				
				count+=1;
				
				return fun(n/2,count);
			
				}
			else{
				count+=1;
				
				return fun(3*n+1,count);
				
				}
		}
int main()
{
		int n,count=0;
	
		cin >> n;
		count=fun(n,count);
	
		cout <<count<<endl;		

}
