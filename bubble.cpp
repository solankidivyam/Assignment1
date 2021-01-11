#include <iostream>
using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
//Implementing the bubble sort algorithm
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  
  
//Funtion to print the array
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " \n";  
    cout << endl;  
}  
  
  
int main()  
{  
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 88, 54, 10};  
    bubbleSort(arr, 10);  
    cout<<"Sorted array: \n";  
    printArray(arr, 10);  
    return 0;  
}  