#include<stdio.h>

int main(){
    int arr[5];
    printf("Enter Elements:\n");
    for(int i=0; i<5; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int i=0; i<4; i++){
        for(int j=0; j<5-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    printf("Sorted Array Elements:");
    for(int i=0; i<5; i++){
        printf("\narr[%d]: %d", i, arr[i]);
    }
    
    return 0;
}

