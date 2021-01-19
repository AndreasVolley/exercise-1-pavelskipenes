// Compile with `gcc foo.c -std=c99 -lpthread`, or use the makefile
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <assert.h>

#define mutex_lock

int i = 0;
static const size_t ITERATIONS = 1000000;

static void *incrementingThreadFunction(void* lock)
{
	for (size_t _ = 0; _ < ITERATIONS; _++) {
#ifdef mutex_lock
		pthread_mutex_lock(lock);
		i++;
		pthread_mutex_unlock(lock);
		return NULL;
#endif
		i++;
	}
	return NULL;
}

static void *decrementingThreadFunction(void* lock)
{
	for (size_t _ = 0; _ < ITERATIONS; _++) {
#ifdef mutex_lock
		pthread_mutex_lock(lock);;
		i--;
		pthread_mutex_unlock(lock);
		return NULL;
#endif
		i--;
	}
	return NULL;
}

int main()
{
	// init variables
	int err;
#ifdef mutex_lock
	pthread_mutex_t lock;
	err = pthread_mutex_init(&lock,NULL);
	assert(err==0);
#endif

	pthread_t incrementingThread, decrementingThread;

	// create threads
	err = pthread_create(&incrementingThread, NULL, incrementingThreadFunction, (void*)&lock);
	assert(err == 0);

	err = pthread_create(&decrementingThread, NULL, decrementingThreadFunction, (void*)&lock);
	assert(err == 0);

	// wait
	pthread_join(incrementingThread, NULL);
	pthread_join(decrementingThread, NULL);

	// cleanup
#ifdef mutex_lock
	pthread_mutex_destroy(&lock);
#endif

	printf("The magic number is: %d\n", i);
	return EXIT_SUCCESS;
}
