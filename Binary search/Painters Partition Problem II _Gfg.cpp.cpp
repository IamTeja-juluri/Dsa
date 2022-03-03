class Solution
{
  public:
  
  
bool partitionPossible(int a[],int n,int k,long long sum){

  const int mod=1000000007;
  long long curr_sum=0;
  int count=1;

  for(int i=0;i<n;i++){
        
       if(a[i]>sum){
       	return false;
       }

       else if( (curr_sum%mod+a[i]%mod)%mod >sum){
       	count+=1;
       	curr_sum=a[i];
       	if(count>k){
       		return false;
       	}
       }
       else{
       	curr_sum=(curr_sum%mod+a[i]%mod)%mod;
       }
  }

  return true;

}
  
  
    long long minTime(int a[], int n, int k)
    {
        
        const int mod=1000000007;
        long long sum=0;
        
        for(int i=0;i<n;i++){
            sum=(sum%mod+a[i]%mod)%mod;
        }
        
        int low=0,high=sum,ans=0;
        
        while(low<=high){
            
            long long mid=low+(high-low)/2;
            
            if(partitionPossible(a,n,k,mid)){
                ans=mid;
                high=(mid-1+mod)%mod;
            }
            else{
                low=(mid%mod+1%mod)%mod;
            }
            
            
        }
        
        return ans;
        
        
    }
};