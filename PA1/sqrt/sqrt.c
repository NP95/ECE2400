#include <stdio.h> 

int mySqrt(int x) 
{
int f = 0;
if (x < 0){
return -1;
}    
while (f*f <= x){
f++;
}
return (f-1); 
}
