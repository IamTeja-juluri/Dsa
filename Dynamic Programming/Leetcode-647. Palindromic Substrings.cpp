class Solution {
public:
    
    int countSubstrings(string s) {
       
        int count=0;
        int n=s.size();
        
      //odd length substrings
       //Treat every idx as middle element and expand towards left and right only if it is substring and keep track of bounds and do the same for even length
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                     count+=1;
                    l--;
                    r++;
                }
                else
                    break;
            }
        }
        
      //even length substrings
        for(int i=0;i<n-1;i++){
            int l=i,r=i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    count+=1;
                    l--;
                    r++;
                }
                else
                    break;
            }
            
        }
        
        return count;     
    }
};
