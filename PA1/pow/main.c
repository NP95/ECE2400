#include <sys/time.h>    
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> 

#define EPSILON 0.0000001

double myPow(double x, int n);
double pow_ref(double x, int n);

double fabs(double a) { return a>=0 ? a : -a; }

int compareDouble(double a, double b) 
{
    if (fabs(a-b) < EPSILON) 
        return 1;
    else 
        return 0;
}

int main() 
{
    FILE *pFile = fopen("input.ref", "r");
    FILE *rFile = fopen("result.txt", "w");

    if (pFile == NULL) {
        fprintf(rFile, "NO INPUT FILE\n");
        fclose(rFile);
        return 1;
    }

    struct timeval start, end;
    double base;
    int exponent;
    fprintf(rFile, "                base\t  exponent\t              result\t  time(us)\tCorrect\n");

    while(fscanf(pFile, "%lf %d", &base, &exponent) == 2) {
        gettimeofday(&start, NULL);
        double result = myPow(base, exponent);
        gettimeofday(&end, NULL);

        fprintf(rFile, "%20f\t%10d\t%20f\t%10ld\t", base, exponent, result, (end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec));

        if (compareDouble(result, pow_ref(base, exponent)))
            fprintf(rFile, "      Y\n");
        else
            fprintf(rFile, "      N\n");
    }

    fclose(pFile);
    fclose(rFile);
    return 0;
}

