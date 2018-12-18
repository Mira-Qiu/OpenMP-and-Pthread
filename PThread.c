#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define ASCIIs 127
#define atmost 1000

char letters[atmost + 1];
int count[ASCIIs];
pthread_mutex_t mutex;

int thread_count;
void *count_charc(void* rank){
    long my_rank = (long)rank;
    long i,index,length = strlen(letters);
    //long local_letter_n = strlen(letters)/thread_count;
    long local_letter_n;
    
    while(length % thread_count != 0)
        length++;local_letter_n = strlen(letters)/thread_count;
    local_letter_n = length/thread_count;
    
    long my_first_letter_n = my_rank *local_letter_n;
    long my_last_letter_n = my_first_letter_n + local_letter_n;
    for( i = my_first_letter_n ; i < my_last_letter_n;i++){
        index = (int)letters[i];
        pthread_mutex_lock(&mutex);
        (count[index])++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    long thread;
    printf("Enter a line not larger than 100 characters.\n");
    fgets(letters, atmost + 1 , stdin);
    
    pthread_t* thread_handles;
    printf("How many threads: \n");
    scanf("%d",&thread_count);
    
    int i;
    for(i = 0; i < ASCIIs;i++){
        count[i] =0;
    }
    
    thread_handles = malloc(thread_count * sizeof(pthread_t));
    pthread_mutex_init(&mutex,NULL);
    for(thread = 0; thread < thread_count; thread++){
        pthread_create(&thread_handles[thread], NULL, count_charc, (void*) thread);
    }
    
    for(thread = 0; thread < thread_count; thread++){
        pthread_join(thread_handles[thread],NULL);
    }
    pthread_mutex_destroy(&mutex);
    for( i = 33; i < ASCIIs ; i++){
        if( count[i] != 0)
            printf("Number of %c is :%d\n",i,count[i]);
    }
    
    return 0;
}
