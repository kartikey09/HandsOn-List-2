/*
============================================================================
Name : Q7
Author : Kartikey Rana
Description :Write a simple program to print the created thread ids.
Date: 29th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *notifier(){
	printf("\ncurrent thread is %ld\n", pthread_self());
}

int main(){
	pthread_t threads[3];

	printf("creating threads 3...\n");
	for(int i = 0; i < 3; i++){
		pthread_create(&threads[i], NULL, notifier, NULL);
	}

	printf("\n threads created");

	for(int i = 0;i < 3; i++){
		pthread_join(threads[i], NULL);
	
	}
	
	printf("\nthreads finished working\n");
	return 0;
}

/*
creating threads 3...

current thread is 281473523446176

current thread is 281473512960416

 threads created
current thread is 281473502474656

threads finished working
*/
