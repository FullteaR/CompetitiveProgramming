#include <iostream>
#include <stdlib.h>
using namespace std;
#define inf 100000000000;

void merge(long* A, int left, int mid, int right, long* counter);
void mergeSort(long* A, int left, int right,long* counter);
void addCounter(long* counter);

int main(void){
  int n;
  cin>>n;
  long* A=(long*)malloc(n*sizeof(long));
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  long* counter=(long*)malloc(sizeof(long));
  *counter=0;
  mergeSort(A,0,n,counter);
  for(int i=0;i<n-1;i++){
    cout<<A[i]<<" ";
  }
  cout<<A[n-1]<<endl;
  cout<<(*counter)<<endl;
  return 0;
}


void merge(long* A, int left, int mid, int right,long* counter){
  int n1=mid-left;
  int n2=right-mid;
  long* L=(long*)malloc(sizeof(long)*(n1+1));
  long* R=(long*)malloc(sizeof(long)*(n2+1));
  for(int i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(int i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1]=inf;
  R[n2]=inf;
  int i=0;
  int j=0;
  for(int k=left;k<right;k++){
    if (L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
    addCounter(counter);
  }
}

void mergeSort(long* A, int left, int right, long* counter){
  if (left+1<right){
    int mid=(left+right)/2;
    mergeSort(A,left,mid,counter);
    mergeSort(A,mid,right,counter);
    merge(A,left,mid,right,counter);
  }
}

void addCounter(long* counter){
  *counter=(*counter)+1;
}
