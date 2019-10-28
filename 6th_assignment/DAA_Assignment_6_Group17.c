#include<stdio.h> 
#include<stdlib.h>
#include<math.h>
#define EPSILON 0.0001 
 
float func(float x,int y) 
{ 
    return x*x - y; 
} 

float derivFunc(double x) 
{ 
    return 2*x; 
} 

void newtonRaphson(float x,int y) 
{ 
    float h = func(x,y) / derivFunc(x);
    while (fabs(h) >= EPSILON) 
    { 
        h = func(x,y)/derivFunc(x);   
        x = x - h; 
    }
     printf("The value of the root is : %f\n", x); 
} 
   
int main() 
{ 
    float x0 = 1.0; // Initial values assumed 
    newtonRaphson(x0,2);
    newtonRaphson(x0,5); 
    return 0; 
} 