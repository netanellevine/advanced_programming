#include "codec.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_WORKING_THREADS 3
#define MAX_POOL_SIZE 100

typedef struct
{
	char data[512];
	int key;
	int id;
} encrypt_data;

void *encrypt_thread(void *arg)
{
	encrypt_data *data = (encrypt_data *)arg;
	printf("thread %d -> data: %s\n\n", data->id, data->data);
	encrypt(data->data, data->key);
	printf("thread %d -> encripted data: %s\n\n", data->id, data->data);
	return NULL;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("usage: key < file \n");
		printf("!! data more than 1024 char will be ignored !!\n");
		return 0;
	}

	int key = atoi(argv[1]);
	printf("key is %i \n", key);

	char c;
	int counter = 0;
	pthread_t pool[MAX_POOL_SIZE];
	encrypt_data data1;
	encrypt_data data2;
	data1.key = key;
	data2.key = key;
	pthread_t thread1, thread2;
	int i = 1;

	while ((c = getchar()) != EOF)
	{
		if (counter % 1024 == 0)
		{
		}

		if (counter < 512)
		{
			data1.data[counter] = c;
		}
		else
		{
			data2.data[counter - 512] = c;
		}

		counter++;

		if (counter == 512)
		{
			data1.id = 1;
			// data1.data[counter] = '\0';
			printf("thread1 starting!\n");
			pthread_create(&thread1, NULL, encrypt_thread, (void *)&data1);
		}

		if (counter == 1023)
		{
			data2.id = 2;
			printf("thread2 starting!\n");
			pthread_create(&thread2, NULL, encrypt_thread, (void *)&data2);
		}
		// printf("counter is: %d\n", counter);
	}
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}
