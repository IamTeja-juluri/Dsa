#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int min1 = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
  
    // If left child is larger than root
    if (l < n && arr[l]<arr[min1])
        min1 = l;
  
    // If right child is larger than largest so far
    if (r < n && arr[r] <arr[min1])
        min1 = r;
  
    // If largest is not root
    if (min1 != i) {
        swap(arr[i], arr[min1]);
  
        // Recursively heapify the affected sub-tree
        heapify(arr, n, min1);
    }
}


void buildheap(int a[],int n)
{
    int j=(n/2)-1;
    for(int i=j;i>=0;i-=1)
    {
        heapify(a,n,i);
    }
    
}

void Insert(int a[],int &n,int key)
{
    n+=1;
    a[n-1]=key;
    int i=n-1;
    while(i>0 && (a[i]<a[(i-1)/2]))
    {
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;
    }
}

void Deleteroot(int a[],int &n)
{
     a[0]=a[n-1];
    n-=1;
    heapify(a,n,0);
}

void Increasekey(int a[],int n,int i)
{
    heapify(a,n,i);
}

void Decreasekey(int a[],int n,int i)
{
    while(i>0 && a[i]<a[(i-1)/2])
    {
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;
    }
}

void printheap(int a[],int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{
  int a[]={4, 10, 3, 5, 1};
  int n=sizeof(a)/sizeof(int);
  buildheap(a,n);
  int ch;
  while(1)
  {
      int key,keyidx;
  printf("1-Insert 2-Deleteroot 3-Increasekey 4-Decreasekey 5-Printheap 6-exit\n");
  printf("Enter your choice\n");
  cin>>ch;
  switch(ch)
  {
      case 1:
      {
       key=34;
      Insert(a,n,key);
      break;
      }
      case 2:
      {
      Deleteroot(a,n);
      break;
      }
      case 3:
      {
       keyidx=0;
      key=51;
      a[keyidx]=key;
      Increasekey(a,n,keyidx);
      break;
      }
      case 4:
      {
       keyidx=3;
       key=2;
      a[keyidx]=key;
      Decreasekey(a,n,keyidx);
      break;
      }
      case 5:
      {
      printheap(a,n);
      break;
      }
      case 6:
      { exit(0); }
      break;
      default:
      cout<<"Enter valid choice"<<"\n";
      break;
  }
  }
    return 0;
}

