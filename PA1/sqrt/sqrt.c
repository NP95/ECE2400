#include <stdio.h> 

int mySqrt(int x) 
{
int f = 100;
if (x < 0){
f = -1;
}    
else{
while (f*f < x){
f++;
}
while (f*f > x){
f--;
}
}
return f; 
}
