bool WoodCutting(vector<int> &a ,int H,int maxHeight){

  int n=a.size();
  int curr_height=0;

  for(int i=0;i<n;i++){
     
     if(maxHeight<a[i]){
         curr_height+=a[i]-maxHeight;
         if(curr_height>=H){
             return true;
         }
     }

  }

  return false;

}



int Solution::solve(vector<int> &a, int H) {
   
   int n=a.size();
   int maxHeight=INT_MIN;
   int minHeight=INT_MAX;

   for(int i=0;i<n;i++){
     maxHeight=max(maxHeight,a[i]);
      minHeight=min(minHeight,a[i]);
   }
   
   int ans;
   int low=minHeight,high=maxHeight;
   
   while(low<=high){
     
     int mid=low+(high-low)/2;

     if(WoodCutting(a,H,mid)){
       ans=mid;
       low=mid+1;
     }
     else{
          high=mid-1;
     }


   }
  
  return ans;

}
