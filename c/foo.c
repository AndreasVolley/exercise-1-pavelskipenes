// Compile with `gcc foo.c -std=c99 -lpthread`, or use the makefile
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

static int i = 0;
const static int ITERATIONS = 1000000;

static void* incrementingThreadFunction(){
    for(size_t _ = 0; _ < ITERATIONS; _++){
        i++;
    }
    return NULL;
}

static void* decrementingThreadFunction(){
    for(size_t _ = 0; _ < ITERATIONS; _++){
        i--;
    }
    return NULL;
}

int main(){
    pthread_t incrementingThread, decrementingThread;

    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
    
    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);
    
    printf("The magic number is: %d\n", i);
    return EXIT_SUCCESS;
}
