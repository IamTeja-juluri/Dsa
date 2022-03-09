class Solution {
public:
    int trap(vector<int>& a) {
        
        
        int n=a.size();
        
        if(n==0)
            return 0;
        
        vector<int> leftmax(n,0);
        vector<int> rightmax(n,0);
        
        int lmax=0;
        int rmax=0;
        
        for(int i=0;i<n;i++){
            
            leftmax[i]=max(lmax,a[i]);
            lmax=max(leftmax[i],lmax);
            
        }
        
         for(int i=n-1;i>=0;i--){
            
             rightmax[i]=max(a[i],rmax);
             rmax=max(rmax,rightmax[i]);
             
        }
        
        int s=0;
        
        for(int i=0;i<n;i++){
            s=s+min(leftmax[i],rightmax[i])-a[i];
        }
        
        return s;
        
    
    }
};
