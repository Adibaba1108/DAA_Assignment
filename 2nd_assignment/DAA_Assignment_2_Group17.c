#include <bits/stdc++.h> 
using namespace std;

unsigned int multiply(unsigned int a, unsigned int b)  //o(log(big number)) multiplication
{ 
    int res = 0;
  
    while (b > 0) 
    { 
         if (b & 1) 
             res = res + a; 
  
         a = a << 1; 
         b = b >> 1; 
     } 
     return res; 
} 

int divide(long long dividend, long long divisor) {   //o(log(big number))
  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; 
  
  dividend = abs(dividend); 
  divisor = abs(divisor); 
   .
  long long quotient = 0, temp = 0; 
  

  for (int i = 31; i >= 0; --i) { 
  
    if (temp + (divisor << i) <= dividend) { 
      temp += divisor << i; 
      quotient |= 1LL << i; 
    } 
  } 
  
  return multiply(sign,quotient); 
} 

int modulo(int a, int b){    // o(2*log(big number))
  int x = divide(a,b);
  int y = multiply(b,x);
  return a-y;
}

int floorSqrt(int x){  //using binary search  O(LOG X)
    if (x == 0 || x == 1)  
       return x; 
   
    int start = 1, end = x, ans;    
    while (start <= end)  
    {         
        int mid = (start + end) / 2; 
  
        if (multiply(mid,mid) == x) 
            return mid; 
   
        if (multiply(mid,mid) < x)  
        { 
            start = mid + 1; 
            ans = mid; 
        }  
        else
            end = mid-1;         
    } 
    return ans; 
} 

bool isNonHypotenuse(int n) 
{ 
    if(n==1)
      return true;
    while (modulo(n,2)== 0) { 
        n = divide(n,2); 
    } 
    int temp = floorSqrt(n);  //o(log(n))
    for (int i = 3; i <= temp; i = i + 2) {    //o(temp/2)[log(n)+log(log(n))]
  
  
        if (modulo(n,i) == 0) {           
            if (modulo((i - 1) , 4) == 0) 
                return false; 
  
            
            while (modulo(n , i) == 0) { 
                n = divide(n,i);
            } 
        } 
    } 
  
    if (n > 2 && modulo((n - 1) , 4) == 0)  //log(n)
        return false; 
  
    else
        return true; 
} 
  
void test(int n) 
{ 
    cout << "Testing for "
         << n << " : "; 
  
    if (isNonHypotenuse(n)) 
        cout << "Not a Hypotenuse"
             << "\n"; 
  
    else
        cout << "Yes it is a Hypotenuse"
             << "\n"; 
} 

  
int main() 
{ 
    float x;
    cin >> x;
    int n = x;
    test(n); 
  
    return 0; 
}
