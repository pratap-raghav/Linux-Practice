#include<stdio.h>

int main(){
	int arr[5], e, idx=-1;
	printf("Enter Elements:\n");
	for(int i=0; i<5; i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter search element: ");
	scanf("%d",&e);
	for(int i=0; i<5; i++){
		if(arr[i]==e){
			idx = i;
		}
	}
	if(idx!=-1){
		printf("Found at: %d", idx);
	}
	else{
		printf("Not found...");
	}
	return 0;
}
