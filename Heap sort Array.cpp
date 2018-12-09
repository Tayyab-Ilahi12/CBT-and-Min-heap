#include<iostream>
using namespace std;



void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; ///////////////////////////////////////////////////////////          a[] = {1,23,4,70,32,22,101,90};
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
void heapsort(int a[],int n)
{
	for(int i = n/2 - 1 ;i >= 0; i--)
	{
		heapify(a,n,i);
	}
	for(int i = n-1;i>= 0;i--)
	{
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
}
void printArray(int a[]) 
{ 
    for (int i=0; i<12; ++i) 
        cout << a[i] << " "; 
    cout << "\n"; 
} 

int main()
{
	int a[] = {1,23,4,70,32,22,101,90,999,291,23};
	int n = sizeof(a)/sizeof(a[0]);
	
	heapsort(a,n);
	printArray(a);
}
