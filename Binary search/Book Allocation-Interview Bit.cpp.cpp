bool can_Allocate(vector<int>&a,int m,int min_sofar){

  int sum=0;
  int count=1;
  int n=a.size();

  for(int i=0;i<n;i++){
       
       if(a[i]>min_sofar){
        return false;
       }

       else if(sum+a[i]>min_sofar){
          
           count+=1;
           sum=a[i];
           if(count>m){
               return false;
           }

       }

       else{
         sum=sum+a[i];
       }

  }

  return true;

}


int Solution::books(vector<int> &a, int m) {
    
    int n=a.size();
    
    if(m>n){
        return -1;
    }

    int sum=0;

    for(int i=0;i<n;i++){

        sum+=a[i];
    }
    
    int low=0;
    int high=sum;
    int ans=INT_MAX;

    while(low<=high){

       int mid=(low+high)/2;

       if(canAllocate(a,m,mid)){
            ans=min(ans,mid);
            high=mid-1;
       }

       else{
           low=mid+1;
       }

    }

   return ans;
}
