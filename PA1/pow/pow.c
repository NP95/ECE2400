#include <stdio.h>

#define EPSILON 0.0000001

double myPow(double x, int n) 
{
// initialize result as one
double f = 1;

// check cases before determining power
if ((x <= EPSILON && x >= -EPSILON) && n < 0){
f = -1;
}
else if ((x <= EPSILON && x >= -EPSILON) && n > 0){
f = 0;
}
else if ((x >= EPSILON || x <= -EPSILON) && n > 0){
for(int i=0;i<n;i++){
    f = f*x;
    }
}
else if ((x >= EPSILON || x <= -EPSILON) && n < 0){
for(int i=0;i<n;i++){
    f = f/x;
    }
}

// return result
return f;
}
