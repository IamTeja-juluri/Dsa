class Solution {
public:
    
    int maximumSum(vector<int>& arr) {
        
        int n=arr.size();
        if(n==0)
            return 0;
        
        if(n==1)
            return arr[0];
        
        if(n==2)
            return max({arr[0],arr[1],arr[0]+arr[1]});

        
        vector<int>forward(n,0);
        vector<int>backward(n,0);
        
        int msf=0;
        
        for(int i=0;i<n;i++){
            
            if(msf+arr[i]<arr[i])
                msf=arr[i];
            else if(msf+arr[i]>=arr[i])
                msf=msf+arr[i];
            
            forward[i]=msf;
        }
        
        msf=0;
        
        for(int i=n-1;i>=0;i--){
            
            if(msf+arr[i]<arr[i])
                msf=arr[i];
            else if(msf+arr[i]>=arr[i])
                msf=msf+arr[i];
            
            backward[i]=msf;
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<n-2;i++){
            ans=max({ans,forward[i]+backward[i+2],forward[i],forward[i]+backward[i+1]});
        }
        
        ans=max({ans,forward[n-1],forward[n-2],forward[n-2]+backward[n-1]});
        return ans;
        
    }
};
