#include <sys/time.h>    
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> 

int mySqrt(int x);
int sqrt_ref(int x);

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
    int base;
    fprintf(rFile, "      base\t    result\t  time(us)\tCorrect\n");

    while(fscanf(pFile, "%d", &base) == 1) {
        gettimeofday(&start, NULL);
        int result = mySqrt(base);
        gettimeofday(&end, NULL);

        fprintf(rFile, "%10d\t%10d\t%10ld\t", base, result, (end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec));

        if (result == sqrt_ref(base)) 
            fprintf(rFile, "      Y\n");
        else
            fprintf(rFile, "      N\n");
    }

    fclose(pFile);
    fclose(rFile);
    return 0;
}

