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
    int lnf=(n/2)-1;  //index of last non leaf node (or) index of last internal node
    for(int i=lnf;i>=0;i-=1)
    {
        heapify(a,n,i);
    }
}
void printheap(int a[],int n)
{
    cout<<"Heapified array is"<<"\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int main()
{
    int a[]={1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    int n=sizeof(a)/sizeof(int);
    buildheap(a,n);
    printheap(a,n);
}

