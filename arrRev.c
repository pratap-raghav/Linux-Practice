#include<stdio.h>

int main(){
	int arr[5], e, idx=-1;
	printf("Enter Elements:\n");
	for(int i=0; i<5; i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i=0; i<(5/2); i++){
		int temp = arr[i];
		arr[i]=arr[5-i-1];
		arr[5-i-1]=temp;
	}
	
	for(int i=0; i<5; i++){
		printf("\n%d", arr[i]);
	}
	return 0;
}
