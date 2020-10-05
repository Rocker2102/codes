#include<bits/stdc++.h>
#include<vector>
using namespace std;

void Merge(int arr[],int left,int mid,int right)
{
  int n1,n2;
  n1=(mid-left+1);
  n2=(right-mid);
  int arr1[n1],arr2[n2];
  for(int i=0;i<n1;i++)
  {
    arr1[i]=arr[left+i];
  }
  for(int i=0;i<n2;i++)
  {
    arr2[i]=arr[mid+i+1];
  }
  int i=0,j=0,k=left;
  while(i<n1 && j<n2)
  {
    if(arr1[i]<=arr2[j])
      arr[k++]=arr1[i++];
    else
      arr[k++]=arr2[j++];
  }
  while(i<n1)
  {
    arr[k++]=arr1[i++];
  }
  while(j<n2)
  {
    arr[k++]=arr2[j++];
  }
}
void Merge_Sort(int arr[],int left,int right)
{
  if(left>=right)
    return;

  int mid=left+(right-left)/2;
  Merge_Sort(arr,left,mid);
  Merge_Sort(arr,mid+1,right);
  Merge(arr,left,mid,right);
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  Merge_Sort(arr,0,n-1);
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
}
