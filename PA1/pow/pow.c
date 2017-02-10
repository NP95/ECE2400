#include <stdio.h>

double myPow(double x, int n) 
{
// initialize result as one
double f = 1;

// check cases before determining power
if (x == 0 && n != 0){
f = 0;
}
else if (x != 0 && n != 0){
for(int i=0;i<n;i++){
    f = f*x;
    }
}

// return result
return f;
}
