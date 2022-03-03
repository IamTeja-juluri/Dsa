#include<bits/stdc++.h>
using namespace std;


void mergesort1(int q[],int low,int high,int mid,int index[]){
    
    int n1=mid-low+1;
    int n2=high-mid;
    int temp1[n1],temp2[n2];
    int temp3[n1],temp4[n2];

    for(int i=0;i<n1;i++){
    	temp1[i]=q[low+i];
      temp3[i]=index[low+i];
    }

    for(int i=0;i<n2;i++){
    	temp2[i]=q[mid+i+1];
      temp4[i]=index[mid+i+1];
    }


    int i=0,j=0,k=low;

    while(i<n1 && j<n2){
      
      if(temp1[i]<=temp2[j]){
      	q[k]=temp1[i];
        index[k]=temp3[i];
        k+=1;
        i+=1;
      }
      
      else{
      	 q[k]=temp2[j];
         index[k]=temp4[j];
         k+=1;
         j+=1;
      }

    }


    while(i<n1){

          q[k]=temp1[i];
          index[k]=temp3[i];
          k+=1;
          i+=1;
    }

    while(j<n2){
  
    	   q[k]=temp2[j];
         index[k]=temp4[j];
         k+=1;
         j+=1;

    }
   

}

void merge1(int q[],int low,int high,int idx[]){
  
  if(low==high){
  	return;
  }
  
  int mid=(low+high)/2;

  merge1(q,low,mid,idx);
  merge1(q,mid+1,high,idx);

  mergesort1(q,low,high,mid,idx);


}

void mergesort(int a[],int low,int mid,int high){
   
   int n1=mid-low+1;
   int n2=high-mid;
    
   int temp1[n1],temp2[n2];

   for(int i=0;i<n1;i++){
   	temp1[i]=a[low+i];
   }

   for(int i=0;i<n2;i++){
   	temp2[i]=a[mid+i+1];
   }
        
   int i=0,j=0,k=low;

   while(i<n1 && j<n2){
       
       if(temp1[i]<=temp2[j]){
       	a[k++]=temp1[i++];
       }
       else{
       	a[k++]=temp2[j++];
       }

   }

   while(i<n1){
   	a[k++]=temp1[i++];
   }

   while(j<n2){
   	a[k++]=temp2[j++];
   }
   

}


void merge(int a[],int low,int high){
   
   if(low==high){
   	return ;
   }
   
   int mid=low+(high-low)/2;

   merge(a,low,mid);
   merge(a,mid+1,high);
   mergesort(a,low,mid,high); 

}


int main(){

	#ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);
	 freopen("output.txt","w",stdout);
	#endif

   int n;
   cin>>n;
   
  int a[n];

   for(int i=0;i<n;i++){
    cin>>a[i];
   }
    
   int nq;
   cin>>nq;

   int query[nq];

   for(int i=0;i<nq;i++){
   	 cin>>query[i];
   } 
   
   merge(a,0,n-1);

   cout<<"Sorted array"<<endl;

   for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
   }


   int index[nq];
   
   for(int i=0;i<nq;i++){
   	index[i]=i;
   } 
    
  
   merge1(query,0,nq-1,index);

   cout<<endl<<"Queries array"<<endl;

    for(int i=0;i<nq;i++){
    cout<<query[i]<<" ";
   }

    cout<<endl<<"Corresponding index array"<<endl;

    for(int i=0;i<nq;i++){
    cout<<index[i]<<" ";
   }


   int freq[nq]={0};

   int p1=0,p2=0;

   
   while(p1<n){

      if(a[p1]==query[p2]){
        freq[p2]+=1;
      }
      else if(query[p2]<a[p1]){
        p2+=1;
      }
       p1+=1;
   }


   cout<<endl<<"Freq wrt sorted queries"<<endl;
   for(int i=0;i<nq;i++){
    cout<<freq[i]<<" ";
   }

   merge1(index,0,nq-1,freq);

   cout<<endl<<"Freq wrt given queries"<<endl;
   for(int i=0;i<nq;i++){
    cout<<freq[i]<<" ";
   }

   cout<<endl<<"index wrt given queries"<<endl;

    for(int i=0;i<nq;i++){
    cout<<index[i]<<" ";
   }
   
   
    
}