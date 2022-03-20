class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
     
        int count=0;
        int n=arr1.size();
        int m=arr2.size();
        
        for(int i=0;i<n;i++){
            bool flag=true;
            for(int j=0;j<m;j++){
                int cond=abs(arr1[i]-arr2[j]);
                if(cond<=d)
                    flag=false;
            }
            if(flag)
                count+=1;
        }
        
        return count;
        
    }
};
