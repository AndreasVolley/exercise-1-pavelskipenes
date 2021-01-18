// Compile with `gcc foo.c -std=c99 -lpthread`, or use the makefile
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <assert.h>

#define mutex_lock

int i = 0;
static const size_t ITERATIONS = 1000000;

static void *incrementingThreadFunction()
{
	for (size_t _ = 0; _ < ITERATIONS; _++) {
#ifdef mutex_lock
		int pthread_mutex_lock(pthread_mutex_t * mutex);
#endif

		i++;

#ifdef mutex_lock
		int pthread_mutex_unlock(pthread_mutex_t * mutex);
#endif
	}
	return NULL;
}

static void *decrementingThreadFunction()
{
	for (size_t _ = 0; _ < ITERATIONS; _++) {

#ifdef mutex_lock
		int pthread_mutex_lock(pthread_mutex_t * mutex);
#endif

		i--;

#ifdef mutex_lock
		int pthread_mutex_unlock(pthread_mutex_t * mutex);
#endif
	}
	return NULL;
}

int main()
{
	// init variables
#ifdef mutex_lock
	int pthread_mutex_init(pthread_mutex_t * restrict mutex, const pthread_mutexattr_t * restrict attr);
#endif
	pthread_t incrementingThread, decrementingThread;
	int err;

	// create threads
	err = pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
	assert(err == 0);

	err = pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
	assert(err == 0);

	// wait
	pthread_join(incrementingThread, NULL);
	pthread_join(decrementingThread, NULL);

	// cleanup
#ifdef mutex_lock
	int pthread_mutex_destroy(pthread_mutex_t * mutex);
#endif

	printf("The magic number is: %d\n", i);
	return EXIT_SUCCESS;
}
