#include<bits/stdc++.h>
using namespace std;
void  heapify(int a[],int n,int i)
{
    int larg=i;
    int l=2*i+1,r=2*i+2;
    if(l<n && a[l]>a[larg])
    larg=l;
    if(r<n && a[r]>a[larg])
    larg=r;
    if(larg!=i)
    {
        swap(a[i],a[larg]);
        heapify(a,n,larg);
    }
}
void buildheap(int a[],int n)
{
    int lnf=(n/2)-1;  //index of last non leaf node (or) index of last inernal node
    for(int i=lnf;i>=0;i-=1)
    {
        heapify(a,n,i);
    }
}
void delelem(int arr[],int &n)
{
    
    // Get the last element
    int lastElement = arr[n - 1];
  
    // Replace root with first element
    arr[0] = lastElement;
  
    // Decrease size of heap by 1
    n = n - 1;
  
    // heapify the root node
    heapify(arr, n, 0);
}
void insert(int a[],int &n,int key)
{
    n+=1;
    a[n-1]=key;
    int i=n-1;
    while(i>0 && (a[i]>a[(i-1)/2]))
    {
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;
    }
}
void increasekey(int a[],int n,int keyidx,int key)
{
    a[keyidx]=key;
    int i=keyidx;
    while(i>0 && a[i]>a[(i-1)/2])
    {
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;
    }
}
void decreasekey(int a[],int n,int keyidx,int key)
{
    a[keyidx]=key;
    heapify(a,n,keyidx);
}
void printheap(int a[],int n)
{
    cout<<"Heapified array is"<<"\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<"\n";
}
int main()
{
    int a[]={1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    int n=sizeof(a)/sizeof(int);
    buildheap(a,n);
    printheap(a,n);
    delelem(a,n);
    printheap(a,n);
    insert(a,n,20);
    printheap(a,n);
    int keyidx=4,key=60;
    increasekey(a,n,keyidx,key);
    printheap(a,n);
    keyidx=5,key=0;
    decreasekey(a,n,keyidx,key);
    printheap(a,n);
}


