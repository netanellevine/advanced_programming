#include "codec.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	char data[] = "my text to encrypt";
	int key = 12;

	encrypt(data, key);
	printf("encripted data: %s\n", data);

	// decrypt(data,key);
	// printf("decripted data: %s\n",data);
	printf("\n\n\n");
	char data1[] = "my ";
	char data2[] = "text ";
	char data3[] = "to ";
	char data4[] = "encrypt";

	encrypt(data1, key);
	printf("encripted data: %s\n", data1);
	encrypt(data2, key);
	printf("encripted data: %s\n", data2);
	encrypt(data3, key);
	printf("encripted data: %s\n", data3);
	encrypt(data4, key);
	printf("encripted data: %s\n", data4);

	// decrypt(data,key);
	// printf("decripted data: %s\n",data);

	return 0;
}
