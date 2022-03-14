class Solution {
public:
    int strStr(string haystack, string needle) {
     
        
        int h=haystack.size();
        int n=needle.size();
        
        if(n==0)
            return 0;
        
        if(n>h)
            return -1;
        
        int idx=-1;
        
        for(int i=0;i<=h-n;i++){
            
            string find=haystack.substr(i,n);
            
            if(find==needle){
                idx=i;
                break;
            }
            
        }
        
        return idx;
    }
};
