#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    int Tserial,Tparallel;
    double S,E;
    int p,n;
    for ( n = 10; n < 321; n *= 2 ){
        Tserial = n * n;
        for( p = 1; p < 129; p *= 2){
            Tparallel = Tserial / p + log(p);
            S = Tserial / (Tparallel * 1.0) ;
            E = S / (p * 1.0);
            printf("When n = %d and p = %d, Speedups = %f and Effciencies = %f.\n", n,p,S,E);
        }
    }
    return 0;
}

