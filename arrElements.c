#include<stdio.h>

int main(){
	int arr[5];
	printf("Enter Elements:\n");
	for(int i=0; i<5; i++){
		scanf("%d", &arr[i]);
	}
	printf("Array Elements:");
	for(int i=0; i<5; i++){
		printf("\narr[%d]: %d", i, arr[i]);
	}
}
