#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>

int findBiggest(int x[], int from, int to)
{
    int big = 0, i;
    for( i = from; i < to; i++)
    	if(big < x[i])
   	 big = x[i];
    return big;
}

int main(){
    int i,a[800],b[8],big,length = 800, thread_count = 8;
    srand((int)time(NULL));
    for( i = 0; i < 800; i++)
    	a[i] = rand()%50001;
#pragma omp parallel num_threads(thread_count)
{
    int rank;
    rank  = omp_get_thread_num();
    b[rank] = findBiggest(a,rank * 100,rank * 100 + 100);
    //printf("The bigget number in b[%d] is %d\n",rank,b[rank]);
}

for ( i = 0; i < 8; i++)
   	big = findBiggest(b,0,8);

printf("The biggest from the entire array is : %d. \n",findBiggest(a,0,length));
printf("The biggest from the nested loop is : %d \n", big);
return 0;
}
