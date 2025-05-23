#include <stdio.h>
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[100],n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    insertionSort(arr,n);
    printf("Sorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}


//OUTPUT:
Enter number of elements: 5
Enter the elements:
1 6 3 4 2
Sorted array: 1 2 3 4 6 
