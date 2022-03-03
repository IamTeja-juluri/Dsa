//Very important
//Binary search on range
//Then apply search in sorted matrix algo
class Solution {
public:
    
    int matrixSearch(vector<vector<int> > &mat,int num){
        
        int n=mat.size(),m=mat[0].size();
        
        int i=n-1,j=0;
        int count=0;
        
        while(i>=0 && j<m){
             
            if(mat[i][j]>num){
                i-=1;
            }
            else{
                count=count+i+1;
                j+=1;
            }
            
        }
        return count;
        
    }
    
    
    
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        
        int low=mat[0][0],high=mat[n-1][m-1];
        
        while(low<high){
            
            int mid=low+(high-low)/2;
            
            int count=matrixSearch(mat,mid);
            if(count<k){
                low=mid+1;
            }
           
          else{
              high=mid;
          }
            
        }
        
        return low;
        
    }
};