#include <stdio.h>
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            int temp=arr[i];arr[i]=arr[j];arr[j]=temp;
        }
    }
    int temp=arr[i+1];arr[i+1]=arr[high];arr[high]=temp;
    return i+1;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int main(){
    int arr[100],size;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    printf("Enter the elements: ");
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    quickSort(arr,0,size-1);
    printf("Sorted array: ");
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}

#OUTPUT:
Enter the size of array: 7
Enter the elements: 22
5
33
75
70
69
85
Sorted array: 5 22 33 69 70 75 85 
