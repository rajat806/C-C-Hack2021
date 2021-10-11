// time complexity -o(nlogn)
//This is the sorting algorithm

#include<iostream>
#include<cstdlib>

using namespace std;

void swap(int *a, int *b) {
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

int Partition(int a[], int l, int h) {
   int pivot, index, i;
   index = l;
   pivot = h;
   for(i = l; i < h; i++) {
      if(a[i] < a[pivot]) {
         swap(&a[i], &a[index]);
         index++;
      }
   }
   swap(&a[pivot], &a[index]);
   return index;
}
int RandomPivotPartition(int a[], int l, int h) {
   int pvt, n, temp;
   n = rand();
   pvt = l + n%(h-l+1);
   swap(&a[h], &a[pvt]);
   return Partition(a, l, h);
}
int QuickSort(int a[], int l, int h) {
   int pindex;
   if(l < h) {
      pindex = RandomPivotPartition(a, l, h);
      QuickSort(a, l, pindex-1);
      QuickSort(a, pindex+1, h);
   }
   return 0;
}
int main() {
   int n;
   cout<<"\nEnter the number size of array : ";
   cin>>n;
   int arr[n];
   for(int i = 0; i < n; i++) {
      cout<<"Enter element "<<i+1<<": ";
      cin>>arr[i];
   }
   QuickSort(arr, 0, n-1);
   cout<<"\nSorted Array : ";
   for (int i = 0; i < n; i++)
      cout<<", "<<arr[i];
   return 0;
}
