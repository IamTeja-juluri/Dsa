class Solution {
public:
    int findLUSlength(string a, string b) {
    
        int n1=a.size();
        int n2=b.size();
        
         if(a==b)
             return -1;
        
        return max(n1,n2);
    }
};
